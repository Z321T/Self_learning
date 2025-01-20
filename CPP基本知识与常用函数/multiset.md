`std::multiset` 是 C++ 标准库中的一个关联容器，设计用于存储有序元素集合，其中可以包含重复元素。它是 `std::set` 的一个扩展，允许重复元素的存在。

### `std::multiset` 数据结构

1. **有序存储**:
   - `std::multiset` 内部使用平衡二叉搜索树（通常是红黑树）来存储元素。元素会按照指定的排序规则自动排序。

2. **重复元素**:
   - 与 `std::set` 不同，`std::multiset` 允许容器中存在多个相同的元素。每个元素都可以有一个计数，表示该元素在容器中出现的次数。

3. **元素访问**:
   - 直接访问（如数组下标）不可用。元素的访问是通过迭代器进行的，迭代器允许遍历和操作集合中的元素。

### 常用的库函数和操作

#### 1. **构造函数**

- **默认构造函数**:
  ```cpp
  std::multiset<int> ms;
  ```
  创建一个空的 `multiset`。

- **指定排序规则**:
  ```cpp
  std::multiset<int, std::greater<int>> ms; // 降序排列
  ```

- **复制构造函数**:
  ```cpp
  std::multiset<int> ms1(ms2); // 复制另一个 multiset
  ```

- **范围构造函数**:
  ```cpp
  std::vector<int> vec = {1, 2, 3};
  std::multiset<int> ms(vec.begin(), vec.end()); // 从容器初始化
  ```

#### 2. **插入元素**

- **单个插入**:
  ```cpp
  ms.insert(5);
  ```

- **插入多个元素**:
  ```cpp
  ms.insert({1, 2, 3});
  ```

- **插入的返回值**:
  ```cpp
  auto result = ms.insert(5);
  if (result.second) {
      std::cout << "Insertion successful" << std::endl;
  }
  ```

#### 3. **查找元素**

- **查找单个元素**:
  ```cpp
  auto it = ms.find(5);
  if (it != ms.end()) {
      std::cout << "Found element: " << *it << std::endl;
  }
  ```

- **查找范围**:
  ```cpp
  auto range = ms.equal_range(5);
  for (auto it = range.first; it != range.second; ++it) {
      std::cout << *it << " ";
  }
  ```

#### 4. **删除元素**

- **删除单个元素**:
  ```cpp
  ms.erase(5);
  ```

- **删除范围**:
  ```cpp
  ms.erase(ms.find(5), ms.end()); // 删除 5 及之后的所有元素
  ```

- **删除特定位置的元素**:
  ```cpp
  auto it = ms.find(5);
  if (it != ms.end()) {
      ms.erase(it);
  }
  ```

#### 5. **其他操作**

- **检查容器是否为空**:
  ```cpp
  if (ms.empty()) {
      std::cout << "The multiset is empty" << std::endl;
  }
  ```

- **获取容器大小**:
  ```cpp
  std::cout << "Size of multiset: " << ms.size() << std::endl;
  ```

- **遍历容器**:
  ```cpp
  for (const auto& elem : ms) {
      std::cout << elem << " ";
  }
  std::cout << std::endl;
  ```

- **获取元素的计数**:
  ```cpp
  std::cout << "Count of 5: " << ms.count(5) << std::endl;
  ```

### 示例代码

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> ms = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // 插入元素
    ms.insert(7);
    
    // 遍历元素
    std::cout << "Elements in multiset: ";
    for (const auto& elem : ms) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 查找和计数
    auto range = ms.equal_range(5);
    std::cout << "Occurrences of 5: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 删除元素
    ms.erase(5);

    // 输出剩余元素
    std::cout << "Elements after deleting 5: ";
    for (const auto& elem : ms) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 总结

- **`std::multiset`** 是一个有序集合容器，允许存储重复元素。
- 提供高效的插入、删除和查找操作。
- 适用于需要维护有序数据且允许重复的场景。
- 使用 `std::multiset` 需要理解其内部排序和重复元素处理的特点。