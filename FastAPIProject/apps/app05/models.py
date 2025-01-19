from tortoise.models import Model
from tortoise import fields

class Student(Model):
    id = fields.IntField(pk=True, description="主键ID")
    name = fields.CharField(max_length=32, description="姓名")
    address = fields.CharField(max_length=32, description="地址", null=True)
    age = fields.IntField(description="年龄", default=18)
    # 一对多关联班级
    class_id = fields.ForeignKeyField("models.Class", related_name="student_class", description="班级")
    # 多对多关联课程
    course = fields.ManyToManyField("models.Course", related_name="students_courses", description="课程")

    class Meta:
        table = "student"

class Class(Model):
    id = fields.IntField(pk=True, description="主键ID")
    name = fields.CharField(max_length=32, description="班级名称")

    class Meta:
        table = "class"

class Course(Model):
    id = fields.IntField(pk=True, description="主键ID")
    name = fields.CharField(max_length=32, description="课程名称")

    class Meta:
        table = "course"