**unordered_map 简介**



unordered_map 是 C++ STL（标准模板库）中一个**基于哈希表（hash table）实现的关联容器。它用于存储键值对（key-value pairs）**，其中键（key）是唯一的，而值（value）可以重复。



与 map（红黑树实现）不同，unordered_map 的**元素存储是无序的**，但其查找、插入和删除的平均时间复杂度为 **O(1)**，比 map 的 O(log n) 更快（但最坏情况下可能是 O(n)）。



------



**unordered_map 相关函数及用法**



**1. 头文件**

```
#include <unordered_map>
```

**2. 基本操作**

```
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> umap;

    // 插入元素（方式1）
    umap["apple"] = 10;
    umap["banana"] = 20;

    // 插入元素（方式2）
    umap.insert({"cherry", 30});

    // 查找元素
    if (umap.find("banana") != umap.end()) {
        std::cout << "banana exists with value: " << umap["banana"] << std::endl;
    }

    // 遍历 unordered_map
    for (const auto& pair : umap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    // 删除元素
    umap.erase("apple");

    return 0;
}
```

**输出示例**

```
banana exists with value: 20
banana -> 20
cherry -> 30
apple -> 10
```

⚠️ **注意**：由于 unordered_map **基于哈希表**，其存储顺序是**无序的**，即输出的键值对顺序可能会不同。



------



**unordered_map 主要成员函数**

| **函数**       | **作用**                                              |
| -------------- | ----------------------------------------------------- |
| insert(pair)   | 插入键值对                                            |
| erase(key)     | 删除指定键的元素                                      |
| find(key)      | 查找元素，返回迭代器                                  |
| count(key)     | 判断某个键是否存在（返回0或1）                        |
| operator[key]  | 访问/插入键值对                                       |
| at(key)        | 访问指定键的值，若不存在则抛出 std::out_of_range 异常 |
| size()         | 返回元素数量                                          |
| empty()        | 判断 unordered_map 是否为空                           |
| clear()        | 清空 unordered_map                                    |
| begin(), end() | 迭代器，遍历元素                                      |
| bucket_count() | 返回桶的数量（哈希桶）                                |
| load_factor()  | 返回当前装载因子                                      |
| rehash(n)      | 重新调整桶的数量，影响哈希冲突                        |
| reserve(n)     | 预留最小桶数，提高性能                                |





------



**3. 详细示例**



**（1）查找 find() 与 count()**

```
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> umap = {{1, "one"}, {2, "two"}, {3, "three"}};

    // 查找 key=2
    auto it = umap.find(2);
    if (it != umap.end()) {
        std::cout << "Found key 2: " << it->second << std::endl;
    }

    // 检测 key 是否存在
    if (umap.count(4) == 0) {
        std::cout << "Key 4 does not exist" << std::endl;
    }

    return 0;
}
```





------



**（2）使用 at() 访问元素**

```
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> umap = {{1, "one"}, {2, "two"}};

    std::cout << umap.at(1) << std::endl;  // 正确
    // std::cout << umap.at(3) << std::endl;  // ⚠️ 抛出异常（key 3 不存在）

    return 0;
}
```

⚠️ **at() 不同于 []，如果 key 不存在会抛出 std::out_of_range 异常！**



------



**（3）插入、删除元素**

```
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> umap;

    // 插入元素
    umap["apple"] = 50;
    umap.insert({"banana", 100});

    // 删除元素
    umap.erase("apple");

    // 遍历 unordered_map
    for (const auto& p : umap) {
        std::cout << p.first << " -> " << p.second << std::endl;
    }

    return 0;
}
```





------



**（4）遍历 unordered_map**

```
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> umap = {{1, "one"}, {2, "two"}, {3, "three"}};

    // 使用迭代器遍历
    for (auto it = umap.begin(); it != umap.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return 0;
}
```





------



**（5）bucket_count() 和 load_factor()**

```
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> umap = {{1, "one"}, {2, "two"}, {3, "three"}};

    std::cout << "Bucket count: " << umap.bucket_count() << std::endl;
    std::cout << "Load factor: " << umap.load_factor() << std::endl;

    return 0;
}
```





------



**4. unordered_map vs map**

| **特性**            | unordered_map                   | map                   |
| ------------------- | ------------------------------- | --------------------- |
| 数据结构            | 哈希表                          | 红黑树                |
| 访问顺序            | 无序                            | 有序（按照 key 排序） |
| 插入/查找时间复杂度 | **O(1)**（平均） / O(n)（最坏） | **O(log n)**          |
| 内存占用            | 较大                            | 较小                  |
| 适用场景            | 需要快速查找的场景              | 需要有序访问的场景    |





------



**5. 适用场景**



**适合使用 unordered_map 的情况**

​	•	需要**高效的键值查找**，如**缓存（cache）**、**字典存储**等

​	•	不关心数据的顺序

​	•	需要 O(1) 级别的查找、插入、删除操作



**适合使用 map 的情况**

​	•	需要**有序存储**

​	•	需要**按键遍历**，如范围查询

​	•	需要较少的内存占用



------



**总结**

​	•	unordered_map **基于哈希表**，查询、插入、删除平均时间复杂度是 O(1)。

​	•	**存储顺序无序**，不适合按顺序遍历的情况。

​	•	提供 **insert()、erase()、find()、at()、count()** 等常见操作。

​	•	适用于 **高效键值查找**，如缓存、计数统计等场景。



如果对顺序没有要求，且需要高效查找，优先使用 unordered_map！