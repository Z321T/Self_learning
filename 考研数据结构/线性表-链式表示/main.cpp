//单链表的定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//单链表初始化-有头节点
bool initList(ListNode* &head) {
    head = new ListNode(0);
    return true;
}
//单链表初始化-无头节点
bool initListNoHead(ListNode* &head) {
    head = nullptr;
    return true;
}
//求单链表的长度
int getLength(ListNode* head) {
    int length = 0;
    ListNode* p = head;
    while (p != nullptr) {
        length++;
        p = p->next;
    }
    return length;
}
//按序号查找结点
ListNode* indexfindNode(ListNode* head, int index) {
    //判断序号是否合法
    if (index < 0 || index >= getLength(head)) {
        return nullptr;
    }
    ListNode* p = head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    return p;
}
//按值查找结点
ListNode* valuefindNode(ListNode* head, int value) {
    ListNode* p = head;
    while (p != nullptr) {
        if (p->val == value) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
//插入结点-尾插法
bool insertNode(ListNode* &head, int i, int value) {
    ListNode* p = head;
    int index = 0;
    while (p != nullptr && index < i - 1) {
        p = p->next;
        index++;
    }
    if (p == nullptr)
        return false;
    ListNode* newNode = new ListNode(value);
    newNode->next = p->next;
    p->next = newNode;

    return true;
}
//插入结点-头插法：同尾插法，只是插入位置不同
//也可以同尾插法一样，只是交换插入后两个结点的值，实现头插法
//删除结点
bool deleteNode(ListNode* &head, int i) {
    ListNode* p = head;
    int index = 0;
    while (p != nullptr && index < i - 1) {
        p = p->next;
        index++;
    }
    if (p == nullptr || p->next == nullptr)
        return false;
    ListNode* q = p->next;
    p->next = q->next;
    delete q;
    return true;
}


//双链表的定义
struct DoubleListNode {
    int val;
    DoubleListNode *prev;
    DoubleListNode *next;
    DoubleListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};
//双链表初始化-有头节点
bool initDoubleList(DoubleListNode* &head) {
    head = new DoubleListNode(0);
    head->prev = head;
    head->next = head;
    return true;
}
//双链表初始化-无头节点
bool initDoubleListNoHead(DoubleListNode* &head) {
    head = nullptr;
    return true;
}
//插入结点-尾插法
bool insertDoubleNode(DoubleListNode* &head, int i, int value) {
    DoubleListNode* p = head;
    int index = 0;
    while (p != nullptr && index < i - 1) {
        p = p->next;
        index++;
    }
    if (p == nullptr)
        return false;
    DoubleListNode* newNode = new DoubleListNode(value);
    newNode->next = p->next;
    newNode->prev = p;
    p->next->prev = newNode;
    p->next = newNode;

    return true;
}
//删除节点
bool deleteDoubleNode(DoubleListNode* &head, int i) {
    DoubleListNode* p = head;
    int index = 0;
    while (p != nullptr && index < i - 1) {
        p = p->next;
        index++;
    }
    if (p == nullptr || p->next == nullptr)
        return false;
    DoubleListNode* q = p->next;
    p->next = q->next;
    q->next->prev = p;
    delete q;
    return true;
}


//循环单链表的定义
struct CircleListNode {
    int val;
    CircleListNode *next;
    CircleListNode(int x) : val(x), next(nullptr) {}
};
//循环双链表的定义
struct CircleDoubleListNode {
    int val;
    CircleDoubleListNode *prev;
    CircleDoubleListNode *next;
    CircleDoubleListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

