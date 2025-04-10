`std::list` 是 C++ 标准库中的双向链表类，提供了许多有用的成员函数。下面列出一些常用的函数，并结合示例说明其用法。

### 常用成员函数

1. **构造函数**
   - `list()`：创建空的 `list`。
   - `list(size_type n, const T& value = T())`：创建包含 `n` 个元素的 `list`，每个元素的值为 `value`。

2. **容量相关函数**
   - `size()`：返回当前元素个数。
   - `empty()`：判断是否为空。
   - `resize(n)`：调整大小为 `n`。

3. **元素访问**
   - `front()`：返回第一个元素。
   - `back()`：返回最后一个元素。

4. **修改器**
   - `push_front(const T& value)`：在开头添加元素。
   - `push_back(const T& value)`：在末尾添加元素。
   - `pop_front()`：移除第一个元素。
   - `pop_back()`：移除最后一个元素。
   - `insert(iterator pos, const T& value)`：在指定位置插入元素。
   - `erase(iterator pos)`：删除指定位置的元素。
   - `clear()`：清除所有元素。

5. **迭代器**
   - `begin()`：返回指向第一个元素的迭代器。
   - `end()`：返回指向末尾元素的下一个位置的迭代器。
   - `rbegin()` 和 `rend()`：用于反向迭代。

### 示例代码

```cpp
#include <iostream>
#include <list>

int main() {
    // 创建一个空的 list
    std::list<int> lst;

    // 添加元素
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    // 输出元素
    std::cout << "List elements: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 输出第一个和最后一个元素
    std::cout << "First element: " << lst.front() << std::endl;
    std::cout << "Last element: " << lst.back() << std::endl;

    // 在开头插入元素
    lst.push_front(5);

    // 在指定位置插入元素
    auto it = lst.begin();
    ++it;
    lst.insert(it, 15);

    // 删除元素
    it = lst.begin();
    ++it;
    lst.erase(it);

    // 输出调整后的 list
    std::cout << "Modified list: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 清空 list
    lst.clear();
    std::cout << "List size after clear: " << lst.size() << std::endl;

    return 0;
}
```

### 解释

- **构造与修改**：通过 `push_front` 和 `push_back` 增加元素，通过 `insert` 和 `erase` 修改指定位置的元素。
- **访问与迭代**：使用 `front` 和 `back` 访问首尾元素，使用迭代器遍历。
- **容量管理**：`resize` 可以调整大小，`clear` 用于清空。

这些函数使 `list` 在插入和删除操作上非常高效，适合频繁插入和删除的场合。