`unordered_set` 是 C++ 中的哈希集合，用于存储唯一元素，无序排列。

### 基本用法

```cpp
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> uset;
    uset.insert(1);
    uset.insert(2);
    uset.insert(3);

    for (int x : uset) {
        std::cout << x << " ";
    }
    return 0;
}
```

### 特性

- **哈希存储**：使用哈希表实现，提供平均常数时间复杂度的插入、删除、查找。
- **无序**：元素没有特定的顺序。

### 常用成员函数

- **`insert()`**：插入元素。
  ```cpp
  uset.insert(4);
  ```
  
- **`erase()`**：移除元素。
  ```cpp
  uset.erase(2);
  ```

- **`find()`**：查找元素，返回迭代器。
  ```cpp
  auto it = uset.find(3);
  if (it != uset.end()) {
      // Found
  }
  ```

- **`count()`**：检查元素是否存在。
  ```cpp
  if (uset.count(1)) {
      // Exists
  }
  ```

- **`size()`**：返回元素数量。
  ```cpp
  std::cout << uset.size();
  ```

- **`empty()`**：检查集合是否为空。
  ```cpp
  if (uset.empty()) {
      // Is empty
  }
  ```

### 使用场景

- 快速查找和去重。
- 存储不需要顺序的唯一元素集合。