/*
问题描述
小蓝认为如果一个数含有偶数个数位，并且前面一半的数位之和等于后面一半的数位之和，则这个数是他的幸运数字。
例如，2314 是一个幸运数字, 因为它有 4 个数位, 并且 2+3=1+4。
现在请你帮他计算从 1 至 100000000 之间共有多少个不同的幸运数字。

答案提交
这是一道结果填空的题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。
 */
#include <iostream>

bool isLuckyNumber(int num) {
    std::string str = std::to_string(num);
    int len = str.length();
    if (len % 2 != 0) return false;

    int half = len / 2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < half; ++i) {
        sum1 += str[i] - '0';
        sum2 += str[i + half] - '0';
    }
    return sum1 == sum2;
}

int main() {
    int count = 0;
    for (int i = 1; i <= 100000000; ++i) {
        if (isLuckyNumber(i)) {
            ++count;
        }
    }
    std::cout << "Number of lucky numbers between 1 and 100000000: " << count << std::endl;
    return 0;
}