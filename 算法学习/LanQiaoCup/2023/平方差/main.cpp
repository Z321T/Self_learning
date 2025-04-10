/*
问题描述
输入两个整数 A 和 B，输出 A^2−B^2 的值。
输入格式
第一行输入一个整数，表示 A。
第二行输入一个整数，表示 B。
输出格式
输出仅一行，包含一个整数，表示答案。

样例输入
20
10
样例输出
300

评测数据规模
对于所有评测数据，-10^100≤A,B≤10^100
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int const N=205;
string stra,strb;
int a[N],b[N],c[N],d[N],e[N];

int main()
{
    cin>>stra>>strb;
    if (!stra.empty() && stra[0] == '-') {
        stra = stra.substr(1);
    }
    if (!strb.empty() && strb[0] == '-') {
        strb = strb.substr(1);
    }
    int flag=0;//标记是否为负数，0为正数，1为负数
    if(stra.length()<strb.length() || stra<strb)//这里很关键，不能直接stra<strb，因为有长度条件
    {
        flag=1;
        string temp=stra;
        stra=strb;
        strb=temp;
    }//确保了a串大于b串
    int lena=stra.length();
    int lenb=strb.length();
    for(int i=0;i<lena;++i)
    {
        a[lena-i-1]=stra[i]-'0';//数组a和b都是从0到lena-1和lenb-1；
    }
    for(int i=0;i<lenb;++i)
    {
        b[lenb-i-1]=strb[i]-'0';
    }
    int andlen=max(lena,lenb);
    for(int i=0;i<andlen;++i)
    {
        c[i]+=a[i]+b[i];
        if(c[i]>9)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    if(c[andlen])++andlen;//和最大可能多一位
    int chalen=max(lena,lenb);
    for(int i=0;i<chalen;++i)
    {
        d[i]+=a[i]-b[i];
        if(d[i]<0)
        {
            --d[i+1];
            d[i]+=10;
        }
    }
    while(chalen>0 && c[chalen]==0)--chalen;//差最少得1位数，1位0
    ++chalen;
    for(int i=0;i<andlen;++i)
    {
        for(int j=0;j<chalen;++j)
        {
            e[i+j]+=c[i]*d[j];
        }
    }
    int chenlen=lena+lenb+1;//乘积的长度多开一个，方便最后while去前导0
    for(int i=0;i<chenlen;++i)
    {
        if(e[i]>9)
        {
            e[i+1]+=e[i]/10;
            e[i]%=10;
        }
    }
    while(e[chenlen]==0)--chenlen;
    if(flag)cout<<'-';
    for(int i=chenlen;i>=0;--i)
        cout<<e[i];
    return 0;
}
