/*
*问题描述

小蓝有一个长度均为 n 且仅由数字字符 0∼9 组成的字符串，下标从 0 ∼ n−1
你可以将其视作是一个具有 n 位的十进制数字 num
小蓝可以从 num 中选出一段连续的子串并将子串进行反转，最多反转一次。
小蓝想要将选出的子串进行反转后再放入原位置处得到的新的数字 num(new)，且num(new) < num
请你帮他计算下一共有多少种不同的子串选择方案
只要两个子串在 num 中的位置不完全相同我们就视作是不同的方案。

注意，我们允许前导零的存在，即数字的最高位可以是 0，这是合法的。

输入格式
输入一行包含一个长度为 n 的字符串表示 num（仅包含数字字符0∼9），从左至右下标依次为 0∼n−1。

输出格式
输出一行包含一个整数表示答案。

样例输入
210102
样例输出
8
 */
#include <iostream>
#include <string>
using namespace std;

long long countReversedSubstrings(const string& s) {
    long long count = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = i; j < (int)s.size(); j++) {
            string temp = s;
            // 反转子串
            int start = i, end = j;
            while (start < end) {
                if (temp[start]<temp[end]) {
                    break;
                }
                if (temp[start]>temp[end]) {
                    count++;
                    break;
                }
                start++;
                end--;
            }
        }
    }
    return count;
}


int main() {
    string s;
    cin >> s;
    cout << countReversedSubstrings(s) << endl;
    return 0;
}