`std::stack` 是 C++ 标准库中提供的一个容器适配器，它基于一个底层容器（通常是 `std::deque` 或 `std::vector`）实现了栈（后进先出，LIFO）的数据结构。栈主要用于需要遵循后进先出（LIFO）原则的场景，比如函数调用的回溯、表达式求值等。

### 主要特点

- **后进先出（LIFO）**: 栈的最顶端元素是最后插入的元素，最早插入的元素在栈底部。
- **对外接口**: 提供了一组简洁的接口来操作栈的元素，但不允许直接访问底层容器的元素。

### 主要成员函数

1. **构造函数**:
   - `stack()`: 默认构造函数，创建一个空栈。
   - `explicit stack(const Container& cont)`: 使用指定的底层容器构造栈。
   - `explicit stack(Container&& cont)`: 使用移动的底层容器构造栈。

2. **基本操作**:
   - `push(const value_type& val)`: 将元素 `val` 压入栈顶。
   - `push(value_type&& val)`: 将元素 `val`（右值）压入栈顶。
   - `pop()`: 移除栈顶元素。
   - `top()`: 返回栈顶元素的引用（不移除元素）。
   - `empty() const`: 检查栈是否为空，返回 `true` 或 `false`。
   - `size() const`: 返回栈中元素的数量。

3. **底层容器操作**:
   - `container_type& c`: 访问底层容器（通常不直接使用）。

### 示例代码

**基本操作**:

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // 压入元素
    s.push(1);
    s.push(2);
    s.push(3);

    // 访问栈顶元素
    cout << "Top element: " << s.top() << endl; // 3

    // 弹出元素
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // 2

    // 检查栈是否为空
    if (!s.empty()) {
        cout << "Stack size: " << s.size() << endl; // 2
    }

    return 0;
}
```

### 栈的底层容器

`std::stack` 使用的底层容器默认是 `std::deque`，但你可以指定其他容器，如 `std::vector`，只要它们支持栈的基本操作（`push_back` 和 `pop_back`）。

**指定底层容器**:

```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    stack<int, vector<int>> s; // 使用 vector 作为底层容器

    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
```

### 注意事项

- `std::stack` 不提供直接访问底层容器的操作，因此你不能随机访问栈中的元素或遍历栈。
- 栈的主要操作（`push`, `pop`, `top`）都是常数时间操作，但 `top` 和 `pop` 在空栈上调用是未定义行为，所以在使用这些操作之前应该检查栈是否为空。

### 总结

`std::stack` 是一个简单而强大的数据结构，适用于需要遵循后进先出原则的应用。通过基本的操作函数，如 `push`、`pop`、`top` 和 `empty`，你可以方便地管理栈的元素。选择合适的底层容器（如 `std::deque` 或 `std::vector`）可以影响栈的性能和特性。