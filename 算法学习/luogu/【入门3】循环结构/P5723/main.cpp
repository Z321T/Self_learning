#include <iostream>
using namespace std;

int main()
{
    const int MAX = 100000;
    int a[MAX];
    fill(a, a + MAX, 1); // 将所有元素初始化为 1

    // 构造质数数组（埃拉托色尼筛法）
    a[0] = a[1] = 0; // 0 和 1 不是质数
    for (int i = 2; i * i < MAX; i++)
    {
        if (a[i] == 1)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                a[j] = 0; // 标记非质数
            }
        }
    }

    int L;
    cin >> L;
    int ans = 0;
    int sum = 0;

    for (int i = 2; i < MAX; i++)
    {
        if (a[i] == 1)
        {
            sum += i;
            if (sum > L)
            {
                cout << ans << endl; // 输出答案
                break;
            }
            ans++;
            cout << i << endl; // 输出当前质数
        }
    }

    return 0;
}