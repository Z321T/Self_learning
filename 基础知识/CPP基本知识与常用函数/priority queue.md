`std::priority_queue` 是 C++ 标准库中的一个容器适配器，它实现了一个优先队列（priority queue）。优先队列是一种特殊类型的队列，其中每个元素都有一个优先级，队列中的元素总是按优先级顺序排列，优先级最高的元素总是位于队列的前面。

### 主要特点

- **优先级顺序**: 元素总是按照优先级排序，优先级最高的元素总是位于队列的前面。
- **对外接口**: 提供了一组接口用于操作优先队列，但不支持直接访问队列中的中间元素。
- **底层容器**: 默认使用 `std::vector` 作为底层容器，内部实现通常是一个最大堆（最大优先队列），但也可以使用自定义的比较器来实现最小堆（最小优先队列）。

### 主要成员函数

#### 构造函数

- **默认构造函数**:
  - `priority_queue();`
  - 创建一个空的优先队列。

- **指定比较器**:
  - `priority_queue(const Compare& comp, const Container& cont = Container());`
  - 使用指定的比较器 `comp` 和底层容器 `cont` 构造优先队列。

#### 基本操作

- **元素访问**:
  - `const value_type& top() const;`
    - 返回优先队列的顶端元素（优先级最高的元素）。

- **修改内容**:
  - `void push(const value_type& value);` / `void push(value_type&& value);`
    - 将元素 `value` 插入到优先队列中。
  - `void pop();`
    - 移除优先队列的顶端元素（优先级最高的元素）。

- **容量和大小**:
  - `bool empty() const;`
    - 检查优先队列是否为空。
  - `size_type size() const;`
    - 返回优先队列中元素的数量。

#### 示例代码

**使用默认比较器（最大堆）**:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    // 插入元素
    pq.push(10);
    pq.push(5);
    pq.push(15);
    pq.push(7);

    // 打印并移除顶端元素
    while (!pq.empty()) {
        cout << pq.top() << " "; // 打印最大元素
        pq.pop();                // 移除顶端元素
    }
    cout << endl;

    return 0;
}
```

**使用自定义比较器（最小堆）**:

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 自定义比较器
struct Compare {
    bool operator()(int a, int b) {
        return a > b; // 最小优先队列
    }
};

int main() {
    priority_queue<int, vector<int>, Compare> pq;

    // 插入元素
    pq.push(10);
    pq.push(5);
    pq.push(15);
    pq.push(7);

    // 打印并移除顶端元素
    while (!pq.empty()) {
        cout << pq.top() << " "; // 打印最小元素
        pq.pop();                // 移除顶端元素
    }
    cout << endl;

    return 0;
}
```

### 成员函数详解

1. **`top()`**:
   - 返回优先队列的顶端元素（即优先级最高的元素）。
   - 不会移除该元素。

2. **`push()`**:
   - 插入一个新的元素，并保持优先队列的顺序。
   - `value_type` 是元素的类型，支持值传递和右值传递。

3. **`pop()`**:
   - 移除优先队列的顶端元素（即优先级最高的元素），并调整堆结构以保持顺序。

4. **`empty()`**:
   - 返回一个布尔值，指示优先队列是否为空。

5. **`size()`**:
   - 返回优先队列中元素的数量。

6. **自定义比较器**:
   - `priority_queue` 支持自定义比较器，通过提供一个比较函数对象来改变优先队列的排序方式。默认情况下，`priority_queue` 是一个最大堆，如果需要最小堆或其他排序方式，可以使用自定义比较器。

### 总结

`std::priority_queue` 提供了一个高效的优先队列实现，适用于需要根据优先级顺序处理元素的场景。通过 `push`、`pop`、`top` 等基本操作，你可以管理和操作优先队列中的元素。使用自定义比较器，你可以灵活地定义优先级排序规则，以适应不同的应用需求。