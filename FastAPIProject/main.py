from fastapi import FastAPI
from fastapi.staticfiles import StaticFiles
from tortoise.contrib.fastapi import register_tortoise
from settings import TORTOISE_ORM

from apps.app01.views import app01
from apps.app02.views import app02
from apps.app03.views import app03
from apps.app04.views import app04
from apps.app05.views import app05

app = FastAPI()

register_tortoise(
    app=app,
    config=TORTOISE_ORM,
)

app.mount("/static", StaticFiles(directory="apps/static"), name="static")

app.include_router(app01, prefix="/app01", tags=["app01接口-数据验证模型、路径参数与查询参数"])
app.include_router(app02, prefix="/app02", tags=["app02接口"])
app.include_router(app03, prefix="/app03", tags=["app03接口-Form表单、文件处理"])
app.include_router(app04, prefix="/app04", tags=["app04接口- request请求处理"])
app.include_router(app05, prefix="/app05", tags=["app05接口-ORM模型、数据库操作"])

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8888)
