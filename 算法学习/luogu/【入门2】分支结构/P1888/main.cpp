#include <iostream>
#include <algorithm>
using namespace std;

// 计算最大公约数的函数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


int main()
{
    int n[3];
    for(int i = 0; i < 3; i++)
    {
        cin >> n[i];
    }
    sort(n, n + 3);

    int numerator = n[0]; // 分子
    int denominator = n[2]; // 分母

    // 计算最大公约数
    int g = gcd(numerator, denominator);

    // 约分
    numerator /= g;
    denominator /= g;

    // 输出结果
    cout << numerator << "/" << denominator << endl;

    return 0;
}