from fastapi import APIRouter
from fastapi import Request
from fastapi.encoders import jsonable_encoder

app04 = APIRouter()

@app04.post("/request_items")
async def read_request_items(request: Request):
    encoded_request = jsonable_encoder({
        "url": str(request.url),
        "method": request.method,
        "headers": dict(request.headers),
        "client": request.client.host
    })
    return encoded_request