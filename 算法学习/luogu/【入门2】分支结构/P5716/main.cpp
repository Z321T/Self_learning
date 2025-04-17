#include <iostream>
using namespace std;
short a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},n=0,s=0;
int main()
{
    cin>>s>>n;
    if(n!=2)cout<<a[n]<<endl;
    else if(s%400==0||(s%4==0&&s%100!=0))cout<<a[n]+1;
    else cout<<a[n]<<endl;

    return 0;
}