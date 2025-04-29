#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int* a = new int[n]; // 动态分配数组
    for (int i = 1; i <= n; i++)
    {
        a[i - 1] = i;
    }

    string s = to_string(x);
    string t;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        t = to_string(a[i]);
        if (t.find(s) != string::npos) // 如果包含子字符串s
        {
            int cou = count(s.begin(), s.end(), s);
            ans += cou; // 统计包含子字符串s的数字个数
        }
    }

    cout << ans; // 输出不包含子字符串s的数字个数

    delete[] a; // 释放动态分配的内存
    return 0;
}