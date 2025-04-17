#include <iostream>
using namespace std;

int a;//a是题目数
int main(){
    cin>>a;
    if(a*5<=a*3+11){//判断谁大谁小
        cout<<"Local"<<endl;
    }else{
        cout<<"Luogu"<<endl;
    }
    return 0;
}