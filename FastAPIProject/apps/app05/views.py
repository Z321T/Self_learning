from fastapi import APIRouter
from .models import Student, Class, Course

app05 = APIRouter()

@app05.get("/get")
async def get():
    students = await Student.all().prefetch_related("class_id", "course")
    result = []
    for student in students:
        result.append({
            "id": student.id,
            "name": student.name,
            "address": student.address,
            "age": student.age,
            "class": {
                "id": student.class_id.id,
                "name": student.class_id.name
            },
            "courses": [{"id": course.id, "name": course.name} for course in student.course]
        })
    return {
        "students": result
    }

@app05.post("/post")
async def post():
    return {"message": "post"}

@app05.put("/put")
async def put():
    return {"message": "put"}

@app05.delete("/delete")
async def delete():
    return {"message": "delete"}

@app05.patch("/patch")
async def patch():
    return {"message": "patch"}

