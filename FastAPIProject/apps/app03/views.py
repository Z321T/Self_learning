from fastapi import APIRouter, File, UploadFile
from fastapi import Form
from typing import List

app03 = APIRouter()

@app03.post("/regin")
async def regin_id(username: str = Form(...), password: str = Form(...)):
    return {
        "username": username,
        "password": password
    }

@app03.post("/file")
async def get_file(file: bytes = File(...)):
    return {
        "file_size": len(file)
    }

@app03.post("/files")
async def get_files(files: List[bytes] = File(...)):
    for file in files:
        print(len(file))
    return {
        "files_size": len(files)
    }

@app03.post("/upload_file")
async def upload_file(file: UploadFile):
    return {
        "file_name": file.filename,
    }