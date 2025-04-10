FastAPI 是一个现代、快速（高性能）的 Web 框架，用于构建 API。它基于 Python 3.7+ 的类型提示（type hints）和异步编程（asyncio）。FastAPI 支持多种 HTTP 请求方法，每种方法都有其特定的用途和功能。以下是 FastAPI 支持的常见 HTTP 请求方法及其功能：

### 1. **GET**
   - **功能**: 用于从服务器获取资源。GET 请求通常用于读取数据，不会对服务器上的资源进行修改。
   - **特点**:
     - 请求参数通常附加在 URL 的查询字符串中。
     - 请求体通常为空。
     - 幂等操作（多次请求不会对资源产生影响）。
   - **示例**:
     ```python
     from fastapi import FastAPI

     app = FastAPI()

     @app.get("/items/{item_id}")
     async def read_item(item_id: int):
         return {"item_id": item_id}
     ```

### 2. **POST**
   - **功能**: 用于向服务器提交数据，通常用于创建新资源或执行某些操作。
   - **特点**:
     - 请求参数通常包含在请求体中。
     - 非幂等操作（多次请求可能会创建多个资源）。
   - **示例**:
     ```python
     from fastapi import FastAPI
     from pydantic import BaseModel

     app = FastAPI()

     class Item(BaseModel):
         name: str
         description: str = None
         price: float
         tax: float = None

     @app.post("/items/")
     async def create_item(item: Item):
         return item
     ```

### 3. **PUT**
   - **功能**: 用于更新服务器上的资源。如果资源不存在，PUT 请求通常会创建该资源。
   - **特点**:
     - 请求参数通常包含在请求体中。
     - 幂等操作（多次请求对资源的影响相同）。
   - **示例**:
     ```python
     from fastapi import FastAPI
     from pydantic import BaseModel

     app = FastAPI()

     class Item(BaseModel):
         name: str
         description: str = None
         price: float
         tax: float = None

     @app.put("/items/{item_id}")
     async def update_item(item_id: int, item: Item):
         return {"item_id": item_id, **item.dict()}
     ```

### 4. **DELETE**
   - **功能**: 用于删除服务器上的资源。
   - **特点**:
     - 请求参数通常附加在 URL 的路径中。
     - 幂等操作（多次请求对资源的影响相同）。
   - **示例**:
     ```python
     from fastapi import FastAPI

     app = FastAPI()

     @app.delete("/items/{item_id}")
     async def delete_item(item_id: int):
         return {"message": f"Item {item_id} deleted"}
     ```

### 5. **PATCH**
   - **功能**: 用于对资源进行部分更新。与 PUT 不同，PATCH 只更新资源的一部分字段。
   - **特点**:
     - 请求参数通常包含在请求体中。
     - 非幂等操作（多次请求可能会对资源产生不同的影响）。
   - **示例**:
     ```python
     from fastapi import FastAPI
     from pydantic import BaseModel

     app = FastAPI()

     class Item(BaseModel):
         name: str = None
         description: str = None
         price: float = None
         tax: float = None

     @app.patch("/items/{item_id}")
     async def update_item(item_id: int, item: Item):
         return {"item_id": item_id, **item.dict()}
     ```

### 6. **HEAD**
   - **功能**: 类似于 GET 请求，但服务器只返回响应头，不返回响应体。通常用于获取资源的元数据。
   - **特点**:
     - 请求参数通常附加在 URL 的查询字符串中。
     - 请求体为空。
     - 幂等操作。
   - **示例**:
     ```python
     from fastapi import FastAPI

     app = FastAPI()

     @app.head("/items/{item_id}")
     async def head_item(item_id: int):
         return {"item_id": item_id}
     ```

### 7. **OPTIONS**
   - **功能**: 用于获取服务器支持的 HTTP 方法。通常用于跨域请求（CORS）预检。
   - **特点**:
     - 请求体为空。
     - 幂等操作。
   - **示例**:
     ```python
     from fastapi import FastAPI

     app = FastAPI()

     @app.options("/items/{item_id}")
     async def options_item(item_id: int):
         return {"allowed_methods": ["GET", "POST", "PUT", "DELETE"]}
     ```

### 8. **TRACE**
   - **功能**: 用于回显服务器收到的请求，通常用于调试。
   - **特点**:
     - 请求体为空。
     - 幂等操作。
   - **示例**:
     ```python
     from fastapi import FastAPI

     app = FastAPI()

     @app.trace("/items/{item_id}")
     async def trace_item(item_id: int):
         return {"item_id": item_id}
     ```

### 9. **CONNECT**
   - **功能**: 用于建立到目标资源的隧道连接，通常用于 HTTPS 代理。
   - **特点**:
     - 请求体为空。
     - 非幂等操作。
   - **示例**:
     ```python
     from fastapi import FastAPI

     app = FastAPI()

     @app.connect("/items/{item_id}")
     async def connect_item(item_id: int):
         return {"item_id": item_id}
     ```

### 总结
FastAPI 支持所有常见的 HTTP 请求方法，每种方法都有其特定的用途和功能。通过合理使用这些方法，可以构建出符合 RESTful 设计原则的 API。