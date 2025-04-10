在 FastAPI 项目中，合理的项目结构对于代码的可维护性、可扩展性和可读性至关重要。以下是一个推荐的 FastAPI 项目结构，结合了最佳实践，适用于中小型项目。

---

### 项目结构示例

```
my_fastapi_project/
├── app/
│   ├── __init__.py
│   ├── main.py                  # FastAPI 应用入口
│   ├── config.py                # 配置文件
│   ├── models/                  # 数据库模型
│   │   ├── __init__.py
│   │   ├── user.py              # 用户模型
│   │   ├── post.py              # 文章模型
│   │   └── base.py              # 基础模型（可选）
│   ├── schemas/                 # Pydantic 数据模型
│   │   ├── __init__.py
│   │   ├── user.py              # 用户相关的数据模型
│   │   ├── post.py              # 文章相关的数据模型
│   │   └── base.py              # 基础数据模型（可选）
│   ├── services/                # 业务逻辑层
│   │   ├── __init__.py
│   │   ├── user_service.py      # 用户相关业务逻辑
│   │   ├── post_service.py      # 文章相关业务逻辑
│   │   └── auth_service.py      # 认证相关业务逻辑
│   ├── routers/                 # 路由层
│   │   ├── __init__.py
│   │   ├── user_router.py       # 用户相关路由
│   │   ├── post_router.py       # 文章相关路由
│   │   └── auth_router.py       # 认证相关路由
│   ├── dependencies/            # 依赖注入
│   │   ├── __init__.py
│   │   ├── auth.py              # 认证依赖
│   │   └── database.py          # 数据库依赖
│   ├── utils/                   # 工具函数
│   │   ├── __init__.py
│   │   ├── security.py          # 安全相关工具（如密码哈希）
│   │   └── logger.py            # 日志工具
│   ├── tests/                   # 测试代码
│   │   ├── __init__.py
│   │   ├── test_user.py         # 用户相关测试
│   │   ├── test_post.py         # 文章相关测试
│   │   └── conftest.py          # 测试配置
│   └── db/                      # 数据库相关
│       ├── __init__.py
│       ├── session.py           # 数据库会话管理
│       └── migrations/          # 数据库迁移脚本
├── requirements.txt             # 项目依赖
├── .env                         # 环境变量
├── .gitignore                   # Git 忽略文件
├── Dockerfile                   # Docker 配置文件
└── README.md                    # 项目说明文档
```

---

### 详细说明

#### 1. **`app/main.py`**
这是 FastAPI 应用的入口文件，负责初始化 FastAPI 应用并加载路由。

```python
from fastapi import FastAPI
from app.routers import user_router, post_router, auth_router
from app.db.session import init_db

app = FastAPI()

# 初始化数据库
init_db()

# 加载路由
app.include_router(user_router.router, prefix="/users", tags=["users"])
app.include_router(post_router.router, prefix="/posts", tags=["posts"])
app.include_router(auth_router.router, prefix="/auth", tags=["auth"])
```

---

#### 2. **`app/config.py`**
配置文件用于集中管理项目的配置项，例如数据库连接、JWT 密钥等。

```python
from pydantic import BaseSettings

class Settings(BaseSettings):
    DATABASE_URL: str = "sqlite:///./test.db"
    SECRET_KEY: str = "your-secret-key"
    ALGORITHM: str = "HS256"
    ACCESS_TOKEN_EXPIRE_MINUTES: int = 30

    class Config:
        env_file = ".env"

settings = Settings()
```

---

#### 3. **`app/models/`**
数据库模型层，使用 ORM（如 SQLAlchemy 或 Tortoise ORM）定义数据库表结构。

```python
# app/models/user.py
from sqlalchemy import Column, Integer, String
from app.db.session import Base

class User(Base):
    __tablename__ = "users"
    id = Column(Integer, primary_key=True, index=True)
    username = Column(String, unique=True, index=True)
    email = Column(String, unique=True, index=True)
    hashed_password = Column(String)
```

---

#### 4. **`app/schemas/`**
Pydantic 数据模型层，用于定义请求和响应的数据结构。

```python
# app/schemas/user.py
from pydantic import BaseModel

class UserCreate(BaseModel):
    username: str
    email: str
    password: str

class UserResponse(BaseModel):
    id: int
    username: str
    email: str

    class Config:
        orm_mode = True
```

---

#### 5. **`app/services/`**
业务逻辑层，负责处理具体的业务逻辑，例如用户注册、登录等。

```python
# app/services/user_service.py
from app.models.user import User
from app.schemas.user import UserCreate, UserResponse
from app.db.session import SessionLocal
from app.utils.security import get_password_hash

def create_user(user: UserCreate):
    db = SessionLocal()
    hashed_password = get_password_hash(user.password)
    db_user = User(username=user.username, email=user.email, hashed_password=hashed_password)
    db.add(db_user)
    db.commit()
    db.refresh(db_user)
    return db_user
```

---

#### 6. **`app/routers/`**
路由层，负责定义 API 路由。

```python
# app/routers/user_router.py
from fastapi import APIRouter, Depends
from app.services.user_service import create_user
from app.schemas.user import UserCreate, UserResponse

router = APIRouter()

@router.post("/", response_model=UserResponse)
def create_new_user(user: UserCreate):
    return create_user(user)
```

---

#### 7. **`app/dependencies/`**
依赖注入层，用于定义全局依赖，例如认证、数据库会话等。

```python
# app/dependencies/auth.py
from fastapi import Depends, HTTPException, status
from fastapi.security import OAuth2PasswordBearer
from app.utils.security import decode_token

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="auth/login")

def get_current_user(token: str = Depends(oauth2_scheme)):
    credentials_exception = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail="Could not validate credentials",
    )
    return decode_token(token, credentials_exception)
```

---

#### 8. **`app/utils/`**
工具函数层，用于存放通用的工具函数，例如密码哈希、日志记录等。

```python
# app/utils/security.py
from passlib.context import CryptContext

pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")

def get_password_hash(password: str):
    return pwd_context.hash(password)

def verify_password(plain_password: str, hashed_password: str):
    return pwd_context.verify(plain_password, hashed_password)
```

---

#### 9. **`app/db/`**
数据库相关代码，包括数据库会话管理和迁移脚本。

```python
# app/db/session.py
from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

SQLALCHEMY_DATABASE_URL = "sqlite:///./test.db"

engine = create_engine(SQLALCHEMY_DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)
Base = declarative_base()

def init_db():
    Base.metadata.create_all(bind=engine)
```

---

#### 10. **`app/tests/`**
测试代码，用于编写单元测试和集成测试。

```python
# app/tests/test_user.py
from fastapi.testclient import TestClient
from app.main import app

client = TestClient(app)

def test_create_user():
    response = client.post("/users/", json={"username": "test", "email": "test@example.com", "password": "test"})
    assert response.status_code == 200
    assert response.json()["username"] == "test"
```

---

### 最佳实践总结

1. **分层设计**：将项目分为路由层、业务逻辑层、数据模型层和工具层，确保职责分离。
2. **依赖注入**：使用 FastAPI 的依赖注入机制管理数据库会话、认证等全局依赖。
3. **配置文件**：使用 `.env` 文件和环境变量管理敏感信息和配置项。
4. **测试驱动开发**：编写单元测试和集成测试，确保代码质量。
5. **日志记录**：在关键位置添加日志记录，方便调试和监控。
6. **文档化**：使用 FastAPI 的自动文档功能（Swagger 和 ReDoc）为 API 提供文档。

通过这种结构化的组织方式，你的 FastAPI 项目将更加清晰、易于维护和扩展。