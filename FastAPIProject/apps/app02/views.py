from fastapi import APIRouter

app02 = APIRouter()

@app02.post("/user")
async def user():
    return {"message": "Hello World User"}