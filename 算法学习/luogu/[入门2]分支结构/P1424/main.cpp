#include <iostream>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;

    int work_days = 0; // 记录工作日天数
    for (int i = 0; i < n; ++i) {
        int day_of_week = (x + i - 1) % 7 + 1; // 计算当前是周几
        if (day_of_week >= 1 && day_of_week <= 5) { // 周一到周五为工作日
            ++work_days;
        }
    }

    cout << work_days * 250; // 每个工作日游泳 250 公里
    return 0;
}