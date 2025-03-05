C++ 的 std::string 是标准模板库（STL）中的一个类，专门用于处理字符串操作。它比 C 语言的 char 数组（C-style string）更安全、更方便，支持丰富的操作方法。



------



**1. std::string 的基本用法**



**（1）定义和初始化**

```
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1;                 // 空字符串
    string s2 = "Hello";       // 直接赋值初始化
    string s3("World");        // 直接初始化
    string s4(s2);             // 拷贝构造
    string s5(5, 'A');         // 生成 "AAAAA"

    cout << s2 << " " << s3 << " " << s5 << endl; // Hello World AAAAA
    return 0;
}
```





------



**2. std::string 的常用操作**



**（1）字符串输入和输出**

```
string str;
cin >> str;     // 读取一个单词（遇到空格、换行停止）
cout << str;
```

**如果要读取整行字符串：**

```
string str;
getline(cin, str);   // 读取整行（包括空格）
```





------



**（2）获取字符串长度**

```
string s = "Hello";
cout << s.size();  // 5
cout << s.length(); // 5 （size() 和 length() 是等价的）
```





------



**（3）拼接字符串**

```
string s1 = "Hello";
string s2 = "World";
string s3 = s1 + " " + s2; // "Hello World"
s1 += " C++";  // s1 变为 "Hello C++"
```





------



**（4）访问和修改字符**

```
string s = "Hello";
cout << s[1];   // 'e'
s[0] = 'M';     // 修改字符串 -> "Mello"

// 使用 `at()` 访问（带边界检查）
cout << s.at(2); 

// 遍历字符串
for (char c : s) {
    cout << c << " ";
}
```





------



**（5）子字符串（提取部分字符串）**

```
string s = "HelloWorld";
string sub = s.substr(5, 3); // 从索引 5 开始，截取 3 个字符 -> "Wor"
cout << sub;
```





------



**（6）查找字符串**

```
string s = "HelloWorld";
size_t pos = s.find("World"); // 找到 "World" 的起始索引
if (pos != string::npos) {   // string::npos 表示未找到
    cout << "Found at index " << pos;
}
```

**常见的查找函数**

```
s.find("o");        // 查找第一个 "o" 的位置
s.rfind("o");       // 逆向查找（最后一个 "o"）
s.find_first_of("aeiou"); // 找到第一个元音字母
s.find_last_of("aeiou");  // 找到最后一个元音字母
```





------



**（7）替换和删除**

```
string s = "HelloWorld";
s.replace(5, 5, " C++"); // 从索引 5 开始，替换 5 个字符为 " C++"
cout << s;  // "Hello C++"

s.erase(5, 3); // 从索引 5 开始删除 3 个字符
cout << s; // "Hello++"
```





------



**（8）插入字符串**

```
string s = "HelloWorld";
s.insert(5, " C++"); // 在索引 5 处插入 " C++"
cout << s;  // "Hello C++World"
```





------



**（9）字符串比较**

```
string s1 = "abc";
string s2 = "abd";
if (s1 == s2) {
    cout << "Equal";
} else if (s1 < s2) {
    cout << "s1 is smaller";
} else {
    cout << "s1 is greater";
}
```

比较规则：

​	•	按字典序（ASCII 码顺序）比较，"abc" < "abd"，因为 ‘c’ < ‘d’

​	•	==、!=、>、< 等都可以直接用



------



**（10）转换大小写**

```
#include <cctype>
string s = "Hello";
for (char &c : s) {
    c = toupper(c); // 转大写
}
cout << s; // "HELLO"

for (char &c : s) {
    c = tolower(c); // 转小写
}
cout << s; // "hello"
```





------



**（11）字符串反转**

```
string s = "Hello";
reverse(s.begin(), s.end());
cout << s; // "olleH"
```





------



**（12）字符串转整数**

```
string s = "12345";
int num = stoi(s); // 转换成 int
long long bigNum = stoll(s); // 转换成 long long
double d = stod("3.14"); // 转换成 double
```

**整数转字符串**

```
int num = 123;
string s = to_string(num);
cout << s;  // "123"
```





------



**3. 总结**

| **操作**   | **方法**                     |
| ---------- | ---------------------------- |
| 读取字符串 | cin >> s; / getline(cin, s); |
| 获取长度   | s.size(); / s.length();      |
| 连接字符串 | s1 + s2; / s1 += s2;         |
| 访问字符   | s[i]; / s.at(i);             |
| 提取子串   | s.substr(pos, len);          |
| 查找子串   | s.find(str); / s.rfind(str); |
| 替换       | s.replace(pos, len, str);    |
| 删除       | s.erase(pos, len);           |
| 插入       | s.insert(pos, str);          |
| 反转       | reverse(s.begin(), s.end()); |
| 大小写转换 | toupper(c); / tolower(c);    |
| 数字转换   | stoi(s); / to_string(num);   |

std::string 是 C++ 中强大的字符串处理工具，掌握这些操作可以极大提升字符串处理的效率。