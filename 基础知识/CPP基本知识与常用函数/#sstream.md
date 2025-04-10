`<sstream>` 头文件是 C++ 标准库的一部分，提供了一些用于处理字符串流的类和函数。它的主要作用是提供与流相关的操作功能，特别是将字符串和流操作结合在一起，使得字符串可以像流一样被操作。这在数据处理和格式化输入输出时非常有用。

### 主要类

1. **`std::istringstream`**:
   - 用于从字符串中读取数据。它的功能类似于 `std::cin`，但数据来源是字符串而不是标准输入流。
   - 常用于将字符串分解成多个数据项或从字符串中提取数据。

   **常用成员函数**:
   - `str()`: 获取或设置流中的字符串内容。
   - `clear()`: 清除流的状态标志，以便可以重新使用流。
   - `getline()`: 从流中读取一行字符串，通常用于逐行读取。

   **示例**:
   ```cpp
   std::string data = "123 456 789";
   std::istringstream iss(data);
   int a, b, c;
   iss >> a >> b >> c; // 从字符串中提取三个整数
   ```

2. **`std::ostringstream`**:
   - 用于将数据写入字符串中。它的功能类似于 `std::cout`，但输出目标是一个字符串。
   - 常用于构建或格式化字符串内容。

   **常用成员函数**:
   - `str()`: 获取或设置流中的字符串内容。
   - `clear()`: 清除流的状态标志，以便可以重新使用流。

   **示例**:
   ```cpp
   std::ostringstream oss;
   oss << "The number is " << 42; // 将格式化的字符串写入流中
   std::string result = oss.str(); // 获取最终的字符串内容
   ```

3. **`std::stringstream`**:
   - 结合了 `std::istringstream` 和 `std::ostringstream` 的功能，既可以从字符串中读取数据，也可以向字符串中写入数据。
   - 常用于需要同时进行读写操作的场景。

   **常用成员函数**:
   - `str()`: 获取或设置流中的字符串内容。
   - `clear()`: 清除流的状态标志，以便可以重新使用流。

   **示例**:
   ```cpp
   std::stringstream ss;
   ss << "Age: " << 30; // 向字符串流中写入数据
   std::string temp;
   int age;
   ss >> temp >> age; // 从字符串流中读取数据
   ```

### 常用功能和操作

- **格式化数据**: 通过流的格式化操作符（如 `<<` 和 `>>`）可以方便地格式化数据。
- **字符串解析**: 使用 `std::istringstream` 来解析字符串，将字符串分解成各个数据项。
- **构建字符串**: 使用 `std::ostringstream` 和 `std::stringstream` 来构建和格式化字符串。

### 示例代码

**从字符串中提取数据**:
```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string data = "100 200 300";
    std::istringstream iss(data);
    int x, y, z;
    iss >> x >> y >> z;
    std::cout << x << " " << y << " " << z << std::endl;
    return 0;
}
```

**构建和格式化字符串**:
```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ostringstream oss;
    int age = 25;
    oss << "I am " << age << " years old.";
    std::string result = oss.str();
    std::cout << result << std::endl;
    return 0;
}
```

### 总结

`<sstream>` 头文件提供了灵活的字符串流处理功能，通过 `std::istringstream`、`std::ostringstream` 和 `std::stringstream` 类，可以方便地从字符串中读取数据、向字符串中写入数据以及同时进行读写操作。这些功能在处理字符串数据和格式化输入输出时非常有用。