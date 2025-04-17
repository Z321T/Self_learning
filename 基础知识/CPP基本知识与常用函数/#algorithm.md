# `<algorithm>` 常用函数详解

`<algorithm>` 是 C++ 标准库中最重要的头文件之一，提供了大量用于操作容器和数据的通用算法。这些算法可以极大地简化代码并提高开发效率。下面我将详细介绍其中最常用的函数及其用法。

## 1. 排序相关算法

### `std::sort` - 快速排序
```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {5, 3, 1, 4, 2};
std::sort(v.begin(), v.end());  // 升序排序
// v = {1, 2, 3, 4, 5}

// 降序排序
std::sort(v.begin(), v.end(), std::greater<int>());
// v = {5, 4, 3, 2, 1}
```

### `std::stable_sort` - 稳定排序
```cpp
struct Student {
    std::string name;
    int score;
};

std::vector<Student> students = {{"Alice", 90}, {"Bob", 85}, {"Cathy", 90}};
std::stable_sort(students.begin(), students.end(), 
    [](const Student& a, const Student& b) { return a.score > b.score; });
// 保持相同分数学生的原始相对顺序
```

### `std::partial_sort` - 部分排序
```cpp
std::vector<int> v = {5, 6, 1, 3, 2, 4};
// 只排序前3个元素
std::partial_sort(v.begin(), v.begin() + 3, v.end());
// v = {1, 2, 3, 6, 5, 4}
```

## 2. 查找算法

### `std::find` - 线性查找
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
auto it = std::find(v.begin(), v.end(), 3);
if (it != v.end()) {
    std::cout << "Found at position: " << std::distance(v.begin(), it);
}
```

### `std::binary_search` - 二分查找
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
bool found = std::binary_search(v.begin(), v.end(), 3);  // true
```

### `std::lower_bound`/`std::upper_bound`
```cpp
std::vector<int> v = {1, 2, 2, 3, 4, 4, 4, 5};
auto lower = std::lower_bound(v.begin(), v.end(), 4);  // 第一个≥4的元素
auto upper = std::upper_bound(v.begin(), v.end(), 4);  // 第一个>4的元素
std::cout << "Number of 4s: " << std::distance(lower, upper);  // 3
```

## 3. 修改序列算法

### `std::copy` - 复制元素
```cpp
std::vector<int> src = {1, 2, 3, 4, 5};
std::vector<int> dst(5);
std::copy(src.begin(), src.end(), dst.begin());
```

### `std::fill` - 填充元素
```cpp
std::vector<int> v(5);
std::fill(v.begin(), v.end(), 42);  // v = {42, 42, 42, 42, 42}
```

### `std::transform` - 转换元素
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::vector<int> squared(v.size());
std::transform(v.begin(), v.end(), squared.begin(),
    [](int x) { return x * x; });
// squared = {1, 4, 9, 16, 25}
```

## 4. 删除/移除算法

### `std::remove` + `erase`
```cpp
std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
auto new_end = std::remove(v.begin(), v.end(), 2);
v.erase(new_end, v.end());  // v = {1, 3, 4, 5}
```

### `std::unique` - 移除相邻重复
```cpp
std::vector<int> v = {1, 1, 2, 2, 3, 3, 3, 4};
auto last = std::unique(v.begin(), v.end());
v.erase(last, v.end());  // v = {1, 2, 3, 4}
```

## 5. 数值算法

### `std::accumulate` - 累加
```cpp
#include <numeric>
std::vector<int> v = {1, 2, 3, 4, 5};
int sum = std::accumulate(v.begin(), v.end(), 0);  // 15
int product = std::accumulate(v.begin(), v.end(), 1, 
    [](int a, int b) { return a * b; });  // 120
```

### `std::count` - 计数
```cpp
std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
int count = std::count(v.begin(), v.end(), 2);  // 3
```

## 6. 其他实用算法

### `std::reverse` - 反转序列
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::reverse(v.begin(), v.end());  // v = {5, 4, 3, 2, 1}
```

### `std::rotate` - 旋转序列
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::rotate(v.begin(), v.begin() + 2, v.end());  // v = {3, 4, 5, 1, 2}
```

### `std::shuffle` - 随机重排
```cpp
#include <random>
std::vector<int> v = {1, 2, 3, 4, 5};
std::random_device rd;
std::mt19937 g(rd());
std::shuffle(v.begin(), v.end(), g);  // 随机顺序
```

## 7. 比较算法

### `std::equal` - 比较序列
```cpp
std::vector<int> v1 = {1, 2, 3};
std::vector<int> v2 = {1, 2, 3};
bool same = std::equal(v1.begin(), v1.end(), v2.begin());  // true
```

### `std::lexicographical_compare` - 字典序比较
```cpp
std::string s1 = "apple";
std::string s2 = "banana";
bool less = std::lexicographical_compare(
    s1.begin(), s1.end(), s2.begin(), s2.end());  // true
```

## 8. 划分算法

### `std::partition` - 划分序列
```cpp
std::vector<int> v = {1, 2, 3, 4, 5, 6};
auto it = std::partition(v.begin(), v.end(), 
    [](int x) { return x % 2 == 0; });
// 偶数在前，奇数在后
// v可能是 {2, 4, 6, 1, 3, 5}
```

## 总结

`<algorithm>` 头文件提供了丰富的算法，可以处理各种常见的数据操作需求。这些算法的主要特点包括：

1. **通用性**：适用于各种容器（vector、list、array等）
2. **高效性**：大多数算法的时间复杂度都是最优的
3. **安全性**：通过迭代器范围检查避免越界
4. **可组合性**：算法可以组合使用实现复杂操作

掌握这些算法可以显著提高C++编程效率和代码质量。建议在实际开发中优先使用这些标准算法，而不是自己实现类似功能。