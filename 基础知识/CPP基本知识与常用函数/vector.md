`std::vector` 是 C++ 标准库中的动态数组类，提供了许多有用的成员函数。下面列出一些常用的函数，并结合示例说明其用法。

### 常用成员函数

1. **构造函数**
   - `vector()`：创建空的 `vector`。
   - `vector(size_type n, const T& value = T())`：创建包含 `n` 个元素的 `vector`，每个元素的值为 `value`。

2. **容量相关函数**
   - `size()`：返回当前元素个数。
   - `capacity()`：返回当前分配的存储空间大小。
   - `empty()`：判断是否为空。
   - `resize(n)`：调整大小为 `n`。
   - `reserve(n)`：增加容量到至少 `n`。

3. **元素访问**
   - `operator[]`：随机访问元素。
   - `at()`：访问元素并检查范围。
   - `front()`：返回第一个元素。
   - `back()`：返回最后一个元素。

4. **修改器**
   - `push_back(const T& value)`：在末尾添加元素。
   - `pop_back()`：移除最后一个元素。
   - `insert(iterator pos, const T& value)`：在指定位置插入元素。
   - `erase(iterator pos)`：删除指定位置的元素。
   - `clear()`：清除所有元素。
   -std::unique 来删除相邻的重复元素

5. **迭代器**
   - `begin()`：返回指向第一个元素的迭代器。
   - `end()`：返回指向末尾元素的下一个位置的迭代器。
   - `rbegin()` 和 `rend()`：用于反向迭代。

### 示例代码

```cpp
#include <iostream>
#include <vector>

int main() {
    // 创建一个空的 vector
    std::vector<int> vec;

    // 添加元素
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // 输出元素
    std::cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 使用 at() 访问元素
    std::cout << "Element at index 1: " << vec.at(1) << std::endl;

    // 修改元素
    vec[1] = 25;

    // 输出第一个和最后一个元素
    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    // 插入元素
    vec.insert(vec.begin() + 1, 15);

    // 删除元素
    vec.erase(vec.begin() + 2);

    //删除重复元素
    auto last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    // 输出调整后的 vector
    std::cout << "Modified vector: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 清空 vector
    vec.clear();
    std::cout << "Vector size after clear: " << vec.size() << std::endl;

    return 0;
}
```

### 解释

- **构造与修改**：通过 `push_back` 增加元素，通过 `insert` 和 `erase` 修改指定位置的元素。
- **访问与迭代**：使用 `at` 和 `operator[]` 访问元素，使用迭代器遍历。
- **容量管理**：`resize` 和 `reserve` 可以调整大小和容量，`clear` 用于清空。

这些函数使 `vector` 在使用上非常灵活，适合动态调整大小的场合。