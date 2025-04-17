# C++ 迭代器详解

迭代器是 C++ 中用于访问和遍历容器元素的通用接口，它提供了一种统一的方式来操作各种不同的容器（如 `vector`、`list`、`map` 等）。迭代器类似于指针，但功能更加强大和安全。

## 迭代器的基本概念

### 迭代器的分类

C++ 中的迭代器分为5种类型，每种类型支持不同的操作：

1. **输入迭代器 (Input Iterator)**：只能读取元素，只能单向移动（如 `istream_iterator`）
2. **输出迭代器 (Output Iterator)**：只能写入元素，只能单向移动（如 `ostream_iterator`）
3. **前向迭代器 (Forward Iterator)**：可读写，只能单向移动（如 `forward_list` 的迭代器）
4. **双向迭代器 (Bidirectional Iterator)**：可读写，可双向移动（如 `list` 的迭代器）
5. **随机访问迭代器 (Random Access Iterator)**：可读写，可随机访问（如 `vector`、`array`、`deque` 的迭代器）

## 迭代器的基本操作

### 获取迭代器

每个标准容器都提供以下方法来获取迭代器：

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// 获取指向第一个元素的迭代器
auto begin_it = vec.begin();

// 获取指向末尾（最后一个元素之后）的迭代器
auto end_it = vec.end();

// C++11 引入的常量迭代器
auto cbegin_it = vec.cbegin();  // const begin
auto cend_it = vec.cend();      // const end

// 反向迭代器
auto rbegin_it = vec.rbegin();  // reverse begin
auto rend_it = vec.rend();      // reverse end
```

### 迭代器的基本使用

```cpp
std::vector<int> vec = {10, 20, 30, 40, 50};

// 1. 遍历容器
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";  // 解引用迭代器获取元素
}

// 2. 修改元素
for (auto it = vec.begin(); it != vec.end(); ++it) {
    *it *= 2;  // 将每个元素乘以2
}

// 3. 使用迭代器算法
auto it = std::find(vec.begin(), vec.end(), 60);
if (it != vec.end()) {
    std::cout << "Found at position: " << std::distance(vec.begin(), it);
}
```

## 迭代器的高级用法

### 迭代器适配器

C++ 提供了一些特殊的迭代器适配器：

#### 1. 插入迭代器

```cpp
#include <iterator>

std::vector<int> vec = {1, 2, 3};
std::vector<int> target;

// 尾部插入
std::copy(vec.begin(), vec.end(), std::back_inserter(target));

// 头部插入
std::copy(vec.begin(), vec.end(), std::front_inserter(target));

// 指定位置插入
auto insert_pos = target.begin() + 1;
std::copy(vec.begin(), vec.end(), std::inserter(target, insert_pos));
```

#### 2. 流迭代器

```cpp
#include <iterator>
#include <vector>
#include <iostream>

// 从标准输入读取整数
std::vector<int> numbers;
std::copy(std::istream_iterator<int>(std::cin),
          std::istream_iterator<int>(),
          std::back_inserter(numbers));

// 输出到标准输出
std::copy(numbers.begin(), numbers.end(),
          std::ostream_iterator<int>(std::cout, " "));
```

### 迭代器与算法

大多数 `<algorithm>` 中的函数都接受迭代器作为参数：

```cpp
std::vector<int> vec = {5, 3, 1, 4, 2};

// 排序
std::sort(vec.begin(), vec.end());

// 反转
std::reverse(vec.begin(), vec.end());

// 查找
auto it = std::lower_bound(vec.begin(), vec.end(), 3);

// 删除重复元素
vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
```

## 迭代器的安全使用

### 迭代器失效问题

某些容器操作会导致迭代器失效：

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
auto it = vec.begin() + 2;  // 指向3

vec.push_back(6);  // 可能导致迭代器失效（如果发生重新分配）
// it 可能不再有效

// 安全做法：在修改容器后重新获取迭代器
it = vec.begin() + 2;
```

### 使用建议

1. 尽量使用范围for循环（C++11）简化迭代：
   ```cpp
   for (const auto& elem : vec) {
       std::cout << elem << " ";
   }
   ```

2. 在需要修改容器结构时（如插入、删除），注意迭代器可能失效

3. 对于复杂操作，考虑使用算法+lambda表达式替代手动迭代

## 自定义迭代器

你可以为自己的数据结构实现迭代器：

```cpp
class MyContainer {
    int data[5] = {1, 2, 3, 4, 5};
public:
    // 自定义迭代器类
    class Iterator {
        int* ptr;
    public:
        explicit Iterator(int* p) : ptr(p) {}
        int& operator*() { return *ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };
    
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + 5); }
};

// 使用自定义迭代器
MyContainer container;
for (auto elem : container) {
    std::cout << elem << " ";
}
```

## 总结

迭代器是C++中强大的抽象工具，它：

1. 提供统一的容器访问接口
2. 支持泛型编程和算法重用
3. 使代码更加清晰和安全
4. 可以与标准算法无缝配合

掌握迭代器的使用是成为高效C++程序员的关键一步。