//队列
//顺序存储
struct SqQueue
{
    int *data;
    int front, rear, size;
};
//初始化
void InitQueue(SqQueue &Q, int size)
{
    Q.data = new int[size];
    Q.size = size;
    Q.front = Q.rear = 0;
}
//判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}
//入队
bool EnQueue(SqQueue &Q, int x)
{
    if ((Q.rear + 1) % Q.size == Q.front)//队满条件：队尾指针+1等于队头指针
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Q.size;//队尾指针指向最后一个元素的下一个位置
    return true;
}
//出队
bool DeQueue(SqQueue &Q, int &x)
{
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Q.size;
    return true;
}



//链式存储
struct LinkNode
{
    int data;
    LinkNode *next;
};
struct LinkQueue
{
    LinkNode *front, *rear;
};
//初始化
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new LinkNode;
    Q.front->next = nullptr;
}
//判断队列是否为空
bool QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
}
//入队
void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = new LinkNode;
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}
//出队
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    return true;
}