`<iomanip>` 是 C++ 标准库中用于格式化输入/输出的头文件，主要与 `iostream` 配合使用。以下是其常用函数的总结：

---

### **1. 设置字段宽度**
- **`setw(int n)`**  
  设置下一次输入/输出的字段宽度（仅对下一次操作有效）。  
  ```cpp
  cout << setw(10) << 42;  // 输出宽度为10，右对齐
  ```

---

### **2. 填充字符控制**
- **`setfill(char c)`**  
  设置填充字符（默认空格），与 `setw` 配合使用。  
  ```cpp
  cout << setfill('*') << setw(10) << 42; // 输出 "********42"
  ```

---

### **3. 浮点数精度**
- **`setprecision(int n)`**  
  设置浮点数的输出精度（有效位数或小数位数，取决于 `fixed`/`scientific`）。  
  ```cpp
  cout << setprecision(3) << 3.14159; // 输出 "3.14"
  ```

---

### **4. 浮点数格式**
- **`fixed`**  
  强制浮点数以小数形式输出（固定小数点）。  
  ```cpp
  cout << fixed << setprecision(2) << 3.14159; // 输出 "3.14"
  ```
- **`scientific`**  
  强制浮点数以科学计数法输出。  
  ```cpp
  cout << scientific << 3.14159; // 输出 "3.141590e+00"
  ```
- **`hexfloat` (C++11)**  
  以十六进制格式输出浮点数。  
- **`defaultfloat` (C++11)**  
  恢复浮点数的默认输出格式。

---

### **5. 整数进制控制**
- **`hex` / `oct` / `dec`**  
  设置整数为十六进制/八进制/十进制输出（需配合 `<ios>`，但常与 `<iomanip>` 共用）。  
  ```cpp
  cout << hex << 255; // 输出 "ff"
  ```
- **`setbase(int base)`**  
  设置整数进制（支持 8、10、16，其他值恢复默认）。  
  ```cpp
  cout << setbase(16) << 255; // 输出 "ff"
  ```

---

### **6. 其他格式控制**
- **`boolalpha` / `noboolalpha`**  
  将布尔值输出为 `true`/`false` 或 `1`/`0`。  
  ```cpp
  cout << boolalpha << true; // 输出 "true"
  ```
- **`showbase` / `noshowbase`**  
  显示/隐藏进制前缀（如 `0x` 表示十六进制）。  
  ```cpp
  cout << showbase << hex << 255; // 输出 "0xff"
  ```
- **`showpoint` / `noshowpoint`**  
  强制显示浮点数的小数点（即使无小数部分）。  
  ```cpp
  cout << showpoint << 42.0; // 输出 "42.0000"
  ```
- **`uppercase` / `nouppercase`**  
  控制科学计数法或十六进制中的字母大小写（如 `E` vs `e`）。  
  ```cpp
  cout << uppercase << scientific << 3.14; // 输出 "3.14E+00"
  ```

---

### **7. 输入/输出对齐**
- **`left` / `right` / `internal`**  
  设置字段内对齐方式（需配合 `setw`）。  
  ```cpp
  cout << left << setw(10) << "Hi";  // 左对齐输出 "Hi        "
  cout << internal << setw(10) << -42; // 符号左对齐，数字右对齐
  ```

---

### **示例代码**
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(10) << setfill('-') << left << "Hello"  // "Hello-----"
         << setprecision(4) << fixed << 3.1415926 << endl; // "3.1416"
    return 0;
}
```

---

### **总结**
`<iomanip>` 主要用于控制输出格式，如宽度、填充、精度、进制等，常与 `cout`/`cin` 流操作符结合使用。注意：部分函数（如 `hex`）实际属于 `<ios>`，但通常与 `<iomanip>` 配合使用。