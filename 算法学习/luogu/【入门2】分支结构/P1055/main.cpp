#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string isbn;
    cin >> isbn;
    string str = isbn;

    // 移除'-'
    str.erase(remove(str.begin(), str.end(), '-'), str.end());

    int n = str.length(), sum=0;
    for (int i=0; i<n-1; i++)
    {
        sum += (str[i] - '0') * (i + 1);  // 注意将字符转换为数字
    }
    int ans = sum%11;
    char correctChar;

    // 确定正确的校验字符
    if (ans == 10) {
        correctChar = 'X';
    }
    else {
        correctChar = ans + '0';  // 将数字转换为字符
    }

    if (str.back() == correctChar)
        cout << "Right";
    else
    {
        isbn.back() = correctChar;  // 替换最后一个字符
        cout << isbn;  // 输出修改后的ISBN
    }

    return 0;
}
// 0-670-82162-4