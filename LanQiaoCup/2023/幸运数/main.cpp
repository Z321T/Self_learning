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