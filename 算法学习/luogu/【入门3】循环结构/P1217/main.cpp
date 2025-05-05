#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false; // 小于等于 1 不是素数
    if (n <= 3) return true;  // 2 和 3 是素数
    if (n % 2 == 0 || n % 3 == 0) return false; // 能被 2 或 3 整除的不是素数

    for (int i = 5; i * i <= n; i += 6) { // 检查从 5 开始的奇数
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool isPalindrome(int n) {
    string str = to_string(n);
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) return false;
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(isPalindrome(i) && isPrime(i)) {
            cout << i << endl;
        }
    }

    return 0;
}
