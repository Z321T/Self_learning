#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    long long Asum = 0, Bsum = 0; // 使用 long long 避免溢出
    int zc = 0, uc = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            Asum += i;
            zc++;
        }
        else
        {
            Bsum += i;
            uc++;
        }
    }

    // 转换为浮点数计算平均值
    double Aavg = static_cast<double>(Asum) / zc;
    double Bavg = static_cast<double>(Bsum) / uc;

    cout << fixed << setprecision(1) << Aavg << " " << Bavg;

    return 0;
}