`#include <queue>` 是 C++ 标准库中的头文件，用于包含队列相关的容器适配器。它主要包含两个容器适配器：`std::queue` 和 `std::priority_queue`。这些适配器封装了底层的序列容器如 `std::deque` 或 `std::vector`，提供了更高层次的队列操作接口。

以下是 `std::queue` 和 `std::priority_queue` 的详细介绍，包括它们常用的库函数与成员函数：

### 1. `std::queue`

`std::queue` 是一个 FIFO（First-In, First-Out）队列适配器。默认情况下，它使用 `std::deque` 作为底层容器，但也可以使用其他容器，如 `std::list`。

#### 常用成员函数：

- **`push(const T& value)`**: 在队列的末尾添加一个元素。
  
  ```cpp
  std::queue<int> q;
  q.push(10);
  ```

- **`pop()`**: 移除队列前端的元素。注意，这个函数不会返回被移除的元素，如果需要访问该元素，请先调用 `front()`。
  
  ```cpp
  q.pop();
  ```

- **`front()`**: 返回队列前端的元素，但不移除它。

  ```cpp
  int frontElement = q.front();
  ```

- **`back()`**: 返回队列末端的元素，但不移除它。

  ```cpp
  int backElement = q.back();
  ```

- **`empty()`**: 检查队列是否为空。如果队列为空，返回 `true`，否则返回 `false`。

  ```cpp
  bool isEmpty = q.empty();
  ```

- **`size()`**: 返回队列中元素的数量。

  ```cpp
  size_t size = q.size();
  ```

#### 示例代码：

```cpp
#include <queue>
#include <iostream>

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "Front: " << q.front() << std::endl;  // 输出 1
    std::cout << "Back: " << q.back() << std::endl;    // 输出 3

    q.pop();  // 移除元素 1

    std::cout << "Front after pop: " << q.front() << std::endl;  // 输出 2
    std::cout << "Size: " << q.size() << std::endl;              // 输出 2

    return 0;
}
```

### 2. `std::priority_queue`

`std::priority_queue` 是一个按照优先级排序的队列，默认是最大堆（最大元素在队首）。可以使用自定义比较器来改变默认的排序规则。

#### 常用成员函数：

- **`push(const T& value)`**: 在队列中插入一个元素。插入后，队列会自动调整以保持堆的性质。
  
  ```cpp
  std::priority_queue<int> pq;
  pq.push(10);
  ```

- **`pop()`**: 移除队列中的最高优先级元素（默认是最大值）。
  
  ```cpp
  pq.pop();
  ```

- **`top()`**: 返回队列中的最高优先级元素。

  ```cpp
  int topElement = pq.top();
  ```

- **`empty()`**: 检查队列是否为空。如果队列为空，返回 `true`，否则返回 `false`。

  ```cpp
  bool isEmpty = pq.empty();
  ```

- **`size()`**: 返回队列中元素的数量。

  ```cpp
  size_t size = pq.size();
  ```

#### 自定义比较器：

默认情况下，`std::priority_queue` 是最大堆。如果你需要最小堆，可以使用自定义比较器。

```cpp
#include <queue>
#include <vector>
#include <functional>
#include <iostream>

int main() {
    // 最小堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    std::cout << "Top element (min heap): " << minHeap.top() << std::endl;  // 输出 5

    return 0;
}
```

### 总结

- **`std::queue`**: 用于简单的 FIFO 队列操作，提供了基本的 `push`、`pop`、`front`、`back` 等成员函数。
  
- **`std::priority_queue`**: 用于实现优先级队列，默认是最大堆，可以通过自定义比较器来创建最小堆，提供了 `push`、`pop`、`top` 等成员函数。

这两个容器适配器都在实现上依赖其他标准容器，如 `std::deque` 和 `std::vector`。根据具体应用场景，可以选择合适的队列类型来使用。