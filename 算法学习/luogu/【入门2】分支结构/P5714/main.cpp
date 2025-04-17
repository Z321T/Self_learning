#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double m, h;
    cin >> m >> h;
    // 计算 BMI
    double bmi = m / (h * h);

    // 判断 BMI 范围
    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    } else if (bmi >= 18.5 && bmi < 24) {
        cout << "Normal" << endl;
    } else {
        // 输出 BMI 值，保留六位有效数字
        cout << setprecision(6) << bmi << endl;
        cout << "Overweight" << endl;
    }

    return 0;
}