from typing import Optional, Union
from pydantic import BaseModel
from datetime import date
from typing import List
from fastapi import APIRouter


app01 = APIRouter()

@app01.get("/")
async def login():
    return {"message": "Hello World App01"}


class User(BaseModel):
    name:str
    age:int
    address:str
    birthday:date
    friends:List[int]
@app01.post("/data")
async def login_data(user: User):
    print(user, type(user))
    print(user.name, user.address)
    return {"message": "app01/data", "data": user.model_dump()}

@app01.get("/chose/{name}")
async def chose(name: str, age: Optional[int] = None, choice: Union[str, int] = "1"):
    return {"message": f"post {name} and {age} and {choice}"}