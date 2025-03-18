//栈
//顺序存储
struct SqStack
{
    int *data;//存放栈中元素
    int top, size;//栈顶指针和栈的最大容量
};
//初始化
void InitStack(SqStack &S, int size)
{
    S.data = new int[size];
    S.size = size;
    S.top = -1;
}
//判断栈是否为空
bool StackEmpty(SqStack S)
{
    return S.top == -1;
}
//入栈
bool Push(SqStack &S, int x)
{
    if (S.top == S.size - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}
//出栈
bool Pop(SqStack &S, int &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}
//取栈顶元素
bool GetTop(SqStack S, int &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

//链式存储
struct LinkNode
{
    int data;
    LinkNode *next;
};
struct LinkStack
{
    LinkNode *top;
};
//初始化
void InitStack(LinkStack &S)
{
    S.top = nullptr;
}
//判断栈是否为空
bool StackEmpty(LinkStack S)
{
    return S.top == nullptr;
}
//入栈
void Push(LinkStack &S, int x)
{
    LinkNode *p = new LinkNode;
    p->data = x;
    p->next = S.top;
    S.top = p;
}
//出栈
bool Pop(LinkStack &S, int &x)
{
    if (S.top == nullptr)
        return false;
    LinkNode *p = S.top;
    x = p->data;
    S.top = p->next;
    delete p;
    return true;
}
//取栈顶元素
bool GetTop(LinkStack S, int &x)
{
    if (S.top == nullptr)
        return false;
    x = S.top->data;
    return true;
}

//共享栈
struct ShStack
{
    int *data;
    int top1, top2, size;
};
//初始化
void InitStack(ShStack &S, int size)
{
    S.data = new int[size];
    S.size = size;
    S.top1 = -1;
    S.top2 = size;
}
//判断栈是否为空
bool StackEmpty(ShStack S, int i)
{
    if (i == 1)
        return S.top1 == -1;
    else
        return S.top2 == S.size;
}
//入栈
bool Push(ShStack &S, int i, int x)
{
    if (S.top1 + 1 == S.top2)
        return false;
    if (i == 1)
        S.data[++S.top1] = x;
    else
        S.data[--S.top2] = x;
    return true;
}
//出栈
bool Pop(ShStack &S, int i, int &x)
{
    if (i == 1)
    {
        if (S.top1 == -1)
            return false;
        x = S.data[S.top1--];
    }
    else
    {
        if (S.top2 == S.size)
            return false;
        x = S.data[S.top2++];
    }
    return true;
}
//取栈顶元素
bool GetTop(ShStack S, int i, int &x)
{
    if (i == 1)
    {
        if (S.top1 == -1)
            return false;
        x = S.data[S.top1];
    }
    else
    {
        if (S.top2 == S.size)
            return false;
        x = S.data[S.top2];
    }
    return true;
}
