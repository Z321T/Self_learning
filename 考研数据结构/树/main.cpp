#include <stack>
#include <iostream>
#include <queue>
using namespace std;

//二叉树的定义
struct BiTNode
{
    int data;
    BiTNode *lchild, *rchild;
};
//顺序存储
int a[101], n = 10;
//链式存储
struct Node
{
    int data;
    Node *lchild, *rchild;
};

//二叉树的遍历
//先序遍历
void preOrder(Node *node)
{
    if (node == nullptr)
        return;
    printf("%d\n", node->data);
    preOrder(node->lchild);
    preOrder(node->rchild);
}
//先序遍历的非递归实现
void non_recursive_preOrder(Node *node)
{
    stack<Node *> s;
    Node *p = node;
    while (p != nullptr || !s.empty())//p不为空或者栈不为空
    {
        while (p != nullptr)
        {
            printf("%d\n", p->data);
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty())//栈不为空
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

//中序遍历
void inOrder(Node *node)
{
    if (node == nullptr)
        return;
    inOrder(node->lchild);
    printf("%d\n", node->data);
    inOrder(node->rchild);
}
//中序遍历的非递归实现
void non_recursive_inOrder(Node *node)
{
    stack<Node *> s;
    Node *p = node;
    while (p != nullptr || !s.empty())//p不为空或者栈不为空
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty())//栈不为空
        {
            p = s.top();
            s.pop();
            printf("%d\n", p->data);
            p = p->rchild;
        }
    }
}

//后序遍历
void postOrder(Node *node)
{
    if (node == nullptr)
        return;
    postOrder(node->lchild);
    postOrder(node->rchild);
    printf("%d\n", node->data);
}
//后序遍历的非递归实现
void non_recursive_postOrder(Node *node)
{
    stack<Node *> s;
    Node *cur; //当前结点
    Node *pre = nullptr; //前一次访问的结点
    s.push(node);
    while (!s.empty())
    {
        cur = s.top();
        if ((cur->lchild == nullptr && cur->rchild == nullptr) || (pre != nullptr && (pre == cur->lchild || pre == cur->rchild)))
        {//如果当前结点没有孩子结点或者孩子节点都已被访问过
            printf("%d\n", cur->data);
            s.pop();
            pre = cur;
        }
        else
        {
            if (cur->rchild != nullptr)
                s.push(cur->rchild);
            if (cur->lchild != nullptr)
                s.push(cur->lchild);
        }
    }
}

//层次遍历
void levelOrder(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        printf("%d\n", p->data);
        if (p->lchild != nullptr)
            q.push(p->lchild);
        if (p->rchild != nullptr)
            q.push(p->rchild);
    }
}

int main()
{
    //顺序存储
    for (int i = 1; i <= n; i++)
        a[i] = i;
    //链式存储
    Node *root = new Node();
    root->data = 1;
    root->lchild = new Node();
    root->lchild->data = 2;
    root->rchild = new Node();
    root->rchild->data = 3;
    root->lchild->lchild = new Node();
    root->lchild->lchild->data = 4;
    root->lchild->rchild = new Node();
    root->lchild->rchild->data = 5;
    root->rchild->lchild = new Node();
    root->rchild->lchild->data = 6;
    root->rchild->rchild = new Node();
    root->rchild->rchild->data = 7;
    //先序遍历
    printf("preOrder:\n");
    preOrder(root);
    //中序遍历
    printf("inOrder:\n");
    inOrder(root);
    //后序遍历
    printf("postOrder:\n");
    postOrder(root);
    //层次遍历
    printf("levelOrder:\n");
    levelOrder(root);
    return 0;
}

//线索二叉树的定义
struct ThreadNode
{
    int data;
    ThreadNode *lchild, *rchild;
    int ltag, rtag;
};
//中序线索化
void inThread(ThreadNode *p, ThreadNode *&pre)
{
    if (p == nullptr)
        return;
    inThread(p->lchild, pre);
    if (p->lchild == nullptr)
    {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != nullptr && pre->rchild == nullptr)
    {
        pre->rchild = p;
        pre->rtag = 1;
    }
    pre = p;
    inThread(p->rchild, pre);
}
//中序线索化的非递归实现
void inThread2(ThreadNode *p)
{
    stack<ThreadNode *> s;
    ThreadNode *pre = nullptr;
    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            if (p->lchild == nullptr)
            {
                p->lchild = pre;
                p->ltag = 1;
            }
            if (pre != nullptr && pre->rchild == nullptr)
            {
                pre->rchild = p;
                pre->rtag = 1;
            }
            pre = p;
            p = p->rchild;
        }
    }
}
//中序遍历线索二叉树
void inOrderInThread(ThreadNode *root)
{
    ThreadNode *p = root;
    while (p != nullptr)
    {
        while (p->ltag == 0)
            p = p->lchild;
        printf("%d\n", p->data);
        while (p->rtag == 1)
        {
            p = p->rchild;
            printf("%d\n", p->data);
        }
        p = p->rchild;
    }
}