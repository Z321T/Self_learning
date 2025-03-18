#include <iostream>
using namespace std;

#define MAXSIZE 20
//静态分配
struct SqList{
    ElemType data[MAXSIZE];
    int length;
};
//初始化
void InitList(SqList &L){
    L.length = 0;
}

//动态分配
struct SeqList{
    ElemType *data;
    int length;
    int MaxSize;
};
//初始化
void InitList(SeqList &L){
    L.data = new ElemType[MAXSIZE];
    L.length = 0;
    L.MaxSize = MAXSIZE;
}

//插入
bool ListInsert(SqList &L, int i, ElemType e){
    if(i<1 || i>L.length+1)
        return false;
    if(L.length >= MAXSIZE)
        return false;
    for(int j=L.length; j>=i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}
//删除
bool ListDelete(SqList &L, int i, ElemType &e){
    if(i<1 || i>L.length)
        return false;
    e = L.data[i-1];
    for(int j=i; j<L.length; j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
//按值查找
int LocateElem(SqList L, ElemType e){
    for(int i=0; i<L.length; i++){
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}

