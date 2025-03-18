#include <iostream>
#include <string>

using namespace std;

// 简单匹配算法
int simpleMatch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // 遍历主串的每一个可能的起始位置
    for (int i = 0; i <= n - m; ++i) {
        int j;
        // 从当前位置开始，逐个字符比较
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                break; // 如果发现不匹配，跳出内层循环
            }
        }
        // 如果内层循环完全匹配，返回当前起始位置
        if (j == m) {
            return i;
        }
    }

    // 如果没有找到匹配的子串，返回-1
    return -1;
}

// KPM算法
int kmpMatch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // 计算next数组
    int next[m];
    next[0] = -1;
    int i = 0, j = -1;
    while (i < m - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }

    // 遍历主串
    i = 0;
    j = 0;
    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }

    // 如果找到匹配的子串，返回起始位置
    if (j == m) {
        return i - j;
    }

    // 如果没有找到匹配的子串，返回-1
    return -1;
}

//kpm算法,使用nextval数组
int kmpMatch2(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // 计算nextval数组
    int nextval[m];
    nextval[0] = -1;
    int i = 0, j = -1;
    while (i < m - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            ++i;
            ++j;
            if (pattern[i] != pattern[j]) {
                nextval[i] = j;
            }
            else {
                nextval[i] = nextval[j];
            }
        }
        else {
            j = nextval[j];
        }
    }

    // 遍历主串
    i = 0;
    j = 0;
    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) {
            ++i;
            ++j;
        }
        else {
            j = nextval[j];
        }
    }

    // 如果找到匹配的子串，返回起始位置
    if (j == m) {
        return i - j;
    }

    // 如果没有找到匹配的子串，返回-1
    return -1;
}


int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    int index = simpleMatch(text, pattern);


    if (index != -1) {
        cout << "Pattern found at index " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    index = kmpMatch(text, pattern);
    if (index != -1) {
        cout << "Pattern found at index " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    index = kmpMatch2(text, pattern);
    if (index != -1) {
        cout << "Pattern found at index " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}