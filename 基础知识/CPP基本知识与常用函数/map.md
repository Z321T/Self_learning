**C++ 的 std::map**



std::map 是 C++ 标准模板库（STL）中的关联容器，提供**键值对（key-value）的存储结构，支持有序**的数据存储，并且基于**红黑树**（Red-Black Tree）实现。因此，它支持高效的插入、删除、查找操作，**所有元素按键（key）自动排序**。



------



**1. std::map 的基本用法**



**（1）定义和初始化**

```
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;  // 创建一个键为 int，值为 string 的 map

    // 插入元素（方式1）
    m.insert({1, "Apple"});
    m.insert(pair<int, string>(2, "Banana"));

    // 插入元素（方式2）
    m[3] = "Cherry";

    // 遍历 map
    for (const auto &p : m) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}
```

**输出：**

```
1 -> Apple
2 -> Banana
3 -> Cherry
```

​	**注意：**std::map 按**键值升序**存储，默认采用**小于号（<）比较**进行排序。



------



**2. std::map 的常用操作**



**（1）插入元素**

```
map<int, string> m;
m[1] = "Hello";    // 方式1
m.insert({2, "World"});  // 方式2
m.insert(pair<int, string>(3, "C++"));  // 方式3
```

**（2）访问元素**

```
cout << m[1];  // 直接访问（如果 key 不存在，会默认插入一个默认值）
cout << m.at(2);  // 使用 at() 访问，key 不存在会抛出异常
```

**（3）遍历 map**

```
// 使用迭代器遍历
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " -> " << it->second << endl;
}

// 使用 range-based for 遍历
for (const auto &p : m) {
    cout << p.first << " -> " << p.second << endl;
}
```

**（4）查找元素**

```
auto it = m.find(2); // 查找 key=2 的元素
if (it != m.end()) {
    cout << "Found: " << it->first << " -> " << it->second;
} else {
    cout << "Not found!";
}
```

**（5）删除元素**

```
m.erase(2);  // 按 key 删除
m.erase(m.begin()); // 删除第一个元素
m.clear();  // 清空整个 map
```

**（6）获取 map 的大小**

```
cout << m.size();  // 获取元素个数
cout << m.empty(); // 判断 map 是否为空
```





------



**3. std::map 的高级功能**



**（1）自定义排序（降序排序）**



默认情况下，std::map 按 **key 升序** 存储。如果需要**降序存储**，可以传入 greater<> 作为比较器：

```
map<int, string, greater<int>> m; // 按 key 降序存储
m[1] = "A";
m[2] = "B";
m[3] = "C";
```

**输出：**

```
3 -> C
2 -> B
1 -> A
```

**（2）使用自定义比较器**



如果 key 是结构体或类，则需要**自定义比较器**：

```
struct Person {
    int age;
    string name;
};

// 自定义比较规则
struct Compare {
    bool operator()(const Person &p1, const Person &p2) const {
        return p1.age < p2.age; // 按年龄升序
    }
};

map<Person, string, Compare> people;
```





------



**4. 总结**

| **操作**     | **方法**                                  |
| ------------ | ----------------------------------------- |
| 插入元素     | m[key] = value; / m.insert({key, value}); |
| 访问元素     | m[key]; / m.at(key);                      |
| 遍历 map     | for (auto &p : m) {}                      |
| 查找元素     | m.find(key);                              |
| 删除元素     | m.erase(key); / m.clear();                |
| 获取大小     | m.size(); / m.empty();                    |
| 自定义排序   | map<int, string, greater<int>>            |
| 自定义比较器 | struct Compare { bool operator()(...); }; |

std::map 是 C++ 强大的关联容器，适用于**有序映射**，当需要**快速查找、插入和删除**操作时，它是非常好的选择。