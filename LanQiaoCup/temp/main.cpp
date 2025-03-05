#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    string s;
    cin>>s;
    if(s[0]=='-') {
        cout<<s.substr(1);
    }
    string s1 = "HelloWorld";
    size_t pos = s1.find("World"); // 找到 "World" 的起始索引
    if (pos != string::npos) {   // string::npos 表示未找到
        cout << "Found at index " << pos;
    }

    string s2 = "HelloWorld";
    s2.replace(5, 5, " C++"); // 从索引 5 开始，替换 5 个字符为 " C++"
    cout << s2;  // "Hello C++"

    s2.erase(5, 3); // 从索引 5 开始删除 3 个字符
    cout << s2; // "Hello+"
    return 0;
}