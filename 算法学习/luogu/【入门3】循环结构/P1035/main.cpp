#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    double sum = 0;
    double i = 1;

    while (sum <= k)
    {
        sum += 1.0 / i;
        i++;
    }
    cout << i - 1; // 输出满足条件的最小值

    return 0;
}