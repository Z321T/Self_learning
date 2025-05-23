#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    stringstream ss;
    for (n++; --n; ss << n);     //把1-n的值都存放到字符串流中
    string s = ss.str();
    cout << count(s.begin(), s.end(), x + '0') << endl;    //运用count函数直接出结果，简简单单
    return 0;
}

//
// int main()
// {
//     long long n,i,x,b,c,t=0;
//     cin>>n>>x;//输入范围与要查的数字；
//     for(i=1;i<=n;i++)//一到n进行循环；
//     {
//         b=i;//为了不改变i的值，就把i赋值给一个数；
//         while(b!=0)//如果b不等于0，继续循环；
//         {
//             c=b%10;//求是否是x，是的话计数器加一；
//             b=b/10;//求下一个数字是否为x；
//             if(c==x) t++;//计数器加一；
//         }
//     }
//     cout<<t<<endl;//输出计数器的数字；
//     return 0;//结束
// }