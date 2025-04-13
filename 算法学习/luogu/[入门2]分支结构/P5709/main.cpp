#include <iostream>
using namespace std;

int m,t,s;
int main()
{
    cin>>m>>t>>s;
    if(t==0)//特判t=0的情况
    {
        cout<<0<<endl;
        return 0;
    }
    if(s%t==0)//如果s是t的整数倍
        cout<<max(m-s/t,0)<<endl;
    else//如果不是
        cout<<max(m-s/t-1,0)<<endl;
    return 0;//程序结束
}