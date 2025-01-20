`std::map` 是 C++ 标准库中的一种关联容器，用于存储键值对。`std::map` 自动对键值对按键进行排序，并提供高效的查找、插入和删除操作。下面列出一些常用的成员函数，并结合示例说明其用法。

### 常用成员函数

1. **构造函数**
   - `map()`：创建空的 `map`。
   - `map(const map& other)`：复制构造函数，创建一个与 `other` 相同的 `map`。

2. **容量相关函数**
   - `size()`：返回当前键值对的数量。
   - `empty()`：判断是否为空。

3. **元素访问**
   - `operator[]`：通过键访问或插入元素。
   - `at(const key_type& k)`：访问指定键的元素，如果键不存在会抛出异常。

4. **修改器**
   - `insert(const value_type& value)`：插入键值对。
   - `erase(iterator pos)`：删除指定位置的键值对。
   - `erase(const key_type& k)`：删除指定键的键值对。
   - `clear()`：清除所有键值对。

5. **查找**
   - `find(const key_type& k)`：查找键 `k`，返回指向该键值对的迭代器，如果未找到则返回 `end()`。
   - `count(const key_type& k)`：返回键 `k` 在 `map` 中的数量（对于 `map` 来说，要么是 0，要么是 1，因为键是唯一的）。

6. **迭代器**
   - `begin()`：返回指向第一个键值对的迭代器。
   - `end()`：返回指向末尾键值对下一个位置的迭代器。
   - `rbegin()` 和 `rend()`：用于反向迭代。

### 示例代码

```cpp
#include <iostream>
#include <map>

int main() {
    // 创建一个空的 map
    std::map<std::string, int> phoneMap;

    // 插入键值对
    phoneMap["310-1010"] = 2;
    phoneMap["487-3279"] = 4;
    phoneMap["888-4567"] = 3;

    // 输出所有键值对
    std::cout << "Phone numbers and their counts:" << std::endl;
    for (const auto &entry : phoneMap) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }

    // 查找某个键值对
    auto it = phoneMap.find("487-3279");
    if (it != phoneMap.end()) {
        std::cout << "Found 487-3279, count: " << it->second << std::endl;
    } else {
        std::cout << "487-3279 not found." << std::endl;
    }

    // 修改键值对
    phoneMap["487-3279"] = 5;

    // 删除键值对
    phoneMap.erase("310-1010");

    // 输出调整后的 map
    std::cout << "Modified phoneMap:" << std::endl;
    for (const auto &entry : phoneMap) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }

    // 清空 map
    phoneMap.clear();
    std::cout << "Map size after clear: " << phoneMap.size() << std::endl;

    return 0;
}
```

### 解释

- **构造与修改**：通过 `operator[]` 和 `insert` 插入或修改键值对，通过 `erase` 删除指定键或位置的键值对。
- **访问与查找**：使用 `at` 和 `operator[]` 访问元素，使用 `find` 查找键值对。
- **迭代与容量管理**：使用迭代器遍历键值对，使用 `size` 和 `empty` 管理 `map` 的容量，`clear` 用于清空所有键值对。

`std::map` 是一种高度优化的关联容器，适合用于需要快速查找、排序或插入键值对的场合。