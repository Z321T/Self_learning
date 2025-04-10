`<iterator>` 头文件是 C++ 标准库中的一个重要头文件，它包含了许多与迭代器操作相关的功能函数和工具。以下是 `<iterator>` 头文件中包含的一些常用的重用函数和工具：

### 1. **`std::advance`**

- **功能**: 移动一个迭代器前进或后退指定的步数。
- **用法**:
  ```cpp
  #include <iterator>

  std::advance(iterator, n);
  ```
  - `iterator`: 目标迭代器。
  - `n`: 移动的步数（正值向前移动，负值向后移动）。

### 2. **`std::distance`**

- **功能**: 计算两个迭代器之间的距离。
- **用法**:
  ```cpp
  #include <iterator>

  auto dist = std::distance(first, last);
  ```
  - `first` 和 `last`: 迭代器范围的起始和结束迭代器。
  - 返回值: `first` 和 `last` 之间的元素数量。

### 3. **`std::next`**

- **功能**: 返回一个指向当前迭代器位置前进指定步数的迭代器。
- **用法**:
  ```cpp
  #include <iterator>

  auto it = std::next(iterator, n);
  ```
  - `iterator`: 初始迭代器。
  - `n`: 需要前进的步数（默认为1）。
  - 返回值: 新的迭代器位置。

### 4. **`std::prev`**

- **功能**: 返回一个指向当前迭代器位置后退指定步数的迭代器。
- **用法**:
  ```cpp
  #include <iterator>

  auto it = std::prev(iterator, n);
  ```
  - `iterator`: 初始迭代器。
  - `n`: 需要后退的步数（默认为1）。
  - 返回值: 新的迭代器位置。

### 5. **`std::iterator_traits`**

- **功能**: 提供关于迭代器的属性的信息，比如迭代器的类别、值类型等。
- **用法**:
  ```cpp
  #include <iterator>

  std::iterator_traits<Iterator>::iterator_category;
  std::iterator_traits<Iterator>::value_type;
  ```
  - `Iterator`: 迭代器类型。
  - 提供迭代器的类别（如随机访问、双向等）、值类型、指针类型等信息。

### 6. **`std::make_move_iterator`**

- **功能**: 生成一个移动迭代器，从一个普通迭代器生成一个可以移动其指向对象的迭代器。
- **用法**:
  ```cpp
  #include <iterator>

  auto move_it = std::make_move_iterator(it);
  ```
  - `it`: 原始迭代器。
  - 返回值: `it` 的移动版本迭代器。

### 7. **`std::insert_iterator`**

- **功能**: 适配器，用于在指定容器中插入元素。
- **用法**:
  ```cpp
  #include <iterator>
  #include <vector>

  std::vector<int> v;
  std::insert_iterator<std::vector<int>> ins_it(v, v.begin());
  *ins_it = 1;
  ```
  - `Container`: 目标容器。
  - `position`: 插入位置。
  - `ins_it`: 插入迭代器。

### 8. **`std::reverse_iterator`**

- **功能**: 反向迭代器，用于反向遍历容器。
- **用法**:
  ```cpp
  #include <iterator>
  #include <vector>

  std::vector<int> v = {1, 2, 3};
  std::reverse_iterator<std::vector<int>::iterator> rit(v.end());
  ```
  - `reverse_iterator`: 提供反向遍历容器的功能。

### 示例代码

以下是一个使用 `<iterator>` 头文件中的函数的示例代码：

```cpp
#include <iostream>
#include <vector>
#include <iterator> // 包含 std::advance, std::distance, std::next, std::prev

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    auto it = v.begin();
    
    // 使用 std::advance 移动迭代器
    std::advance(it, 2);
    std::cout << "Element after advancing 2 steps: " << *it << std::endl;

    // 使用 std::distance 计算迭代器距离
    auto dist = std::distance(v.begin(), it);
    std::cout << "Distance from begin to current iterator: " << dist << std::endl;

    // 使用 std::next 获取下一个迭代器
    auto next_it = std::next(it);
    std::cout << "Element at next iterator: " << *next_it << std::endl;

    // 使用 std::prev 获取前一个迭代器
    auto prev_it = std::prev(it);
    std::cout << "Element at previous iterator: " << *prev_it << std::endl;

    return 0;
}
```

### 总结

- **`<iterator>`** 头文件提供了许多与迭代器操作相关的函数和工具。
- 这些函数支持高效的迭代器操作，包括移动、计算距离和创建反向迭代器等。
- 使用这些工具可以更灵活和高效地操作容器和迭代器。