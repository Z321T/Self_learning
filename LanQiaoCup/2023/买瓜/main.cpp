/*
*问题描述
小蓝正在一个瓜摊上买瓜。瓜摊上共有 n 个瓜，每个瓜的重量为 A(i)
小蓝刀功了得，他可以把任何瓜劈成完全等重的两份，不过每个瓜只能劈一刀。
小蓝希望买到的瓜的重量的和恰好为 m。

请问小蓝至少要劈多少个瓜才能买到重量恰好为 m 的瓜。如果无论怎样小蓝都无法得到总重恰好为 m 的瓜，请输出 −1。

输入格式
输入的第一行包含两个整数 n，m，用一个空格分隔，分别表示瓜的个数和小蓝想买到的瓜的总重量。

第二行包含 n 个整数，相邻整数之间使用一个空格分隔，分别表示每个瓜的重量。

输出格式
输出一行包含一个整数表示答案。
 */
#include <iostream>
#include <algorithm>
using namespace std;
int n,ans=50;
long long m,a[50],sum[50];

void dfs(long long S,int i,int cnt){//S为当前选择的瓜的重量总和，i为当前处理的瓜的下标，cnt为当前的劈刀数
    if(cnt>=ans) return;//剪枝
    if(S==m) ans=cnt;//更新答案
    if(i>n||S>m||S+sum[i]<m) return;
    dfs(S,i+1,cnt);
    dfs(S+a[i],i+1,cnt);
    dfs(S+a[i]/2,i+1,cnt+1);
}

int main()
{
    cin>>n>>m;
    m<<=1;
    for(int i=0;i<n;++i){
        cin>>a[i];
        a[i]<<=1;
    }
    sort(a,a+n,greater<>());
    for(int i=n-1;i>=0;--i){
        sum[i]=sum[i+1]+a[i];
    }
    dfs(0,0,0);
    if(ans==50){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}