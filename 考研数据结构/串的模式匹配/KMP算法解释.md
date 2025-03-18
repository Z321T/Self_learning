这段代码实现了**KMP（Knuth-Morris-Pratt）字符串匹配算法**，KMP算法的核心思想是**利用已经匹配的信息，避免重复匹配，提高效率**。它的时间复杂度为 **O(n + m)**，相比于暴力匹配（O(n × m)），在长文本搜索时更高效。



接下来，我们详细解析这段代码的逻辑，包括**next 数组的计算**和**主串的匹配过程**。

**1. 代码解析**

```
int kmpMatch(const string& text, const string& pattern) {
```

​	•	**函数声明**：

​	•	kmpMatch 是函数名。

​	•	text 是主串（目标字符串）。

​	•	pattern 是模式串（需要匹配的字符串）。

​	•	返回值为 int，表示 pattern **在 text 中首次出现的起始位置**，若匹配失败则返回 -1。

**1.1 计算 next 数组**

```
    int n = text.length();
    int m = pattern.length();

    // 计算next数组
    int next[m];
    next[0] = -1;
    int i = 0, j = -1;
    while (i < m - 1) {
```

​	•	next[i] 代表**模式串 pattern 在 i 位置之前的最长相同前后缀长度**。

​	•	next[0] = -1，表示第一个字符没有前后缀匹配。

​	•	i 遍历 pattern，j 记录当前的最长前后缀长度。

​	•	while (i < m - 1) 用于计算 next 数组。

```
        if (j == -1 || pattern[i] == pattern[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
```

​	•	**如果 pattern[i] == pattern[j]**：

​	•	说明当前位置 i 的前后缀可以继续扩展。

​	•	next[i] = j 记录当前最长前后缀长度。

​	•	**如果 pattern[i] != pattern[j]**：

​	•	说明当前匹配失败，需要回溯 j。

​	•	j = next[j]，让 j 回到之前匹配过的位置，尝试新的前后缀匹配。

**举例计算 next 数组**



假设 pattern = "ABABC"，求 next 数组：

| i    | pattern[i] | j    | next[i] | **解释**           |
| ---- | ---------- | ---- | ------- | ------------------ |
| 0    | A          | -1   | -1      | 初始状态           |
| 1    | B          | 0    | 0       | AB 无相同前后缀    |
| 2    | A          | 1    | 1       | ABA 的前后缀 A     |
| 3    | B          | 2    | 2       | ABAB 的前后缀 AB   |
| 4    | C          | 0    | 0       | ABABC 无更长前后缀 |

得到 next = [-1, 0, 1, 2, 0]。

**1.2 在 text 中查找 pattern**

```
    // 遍历主串
    i = 0;
    j = 0;
    while (i < n && j < m) {
```

​	•	i 遍历主串 text，j 遍历模式串 pattern。

​	•	目标是寻找 pattern 在 text 中的**第一个匹配位置**。

```
        if (j == -1 || text[i] == pattern[j]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
```

​	•	**如果 text[i] == pattern[j]**，说明当前字符匹配：

​	•	++i，继续匹配 text。

​	•	++j，继续匹配 pattern。

​	•	**如果 text[i] != pattern[j]**：

​	•	说明匹配失败，需要回溯 pattern。

​	•	j = next[j]，利用 next 数组跳过部分匹配失败的位置，避免重复计算。

```
    // 如果找到匹配的子串，返回起始位置
    if (j == m) {
        return i - j;
    }

    // 如果没有找到匹配的子串，返回-1
    return -1;
```

​	•	**匹配成功**：如果 j == m，说明 pattern 已匹配完，返回匹配的起始位置 i - j。

​	•	**匹配失败**：返回 -1。

**2. 代码示例**

```
#include <iostream>
using namespace std;

int main() {
    string text = "ababcabcacbab";
    string pattern = "abcac";

    int result = kmpMatch(text, pattern);

    if (result != -1) {
        cout << "Pattern found at index: " << result << endl;
    } else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}
```

**输出**：

```
Pattern found at index: 5
```

模式串 "abcac" 在主串 "ababcabcacbab" 中的索引 5 处首次出现。

**3. 时间复杂度分析**



KMP 的时间复杂度是 **O(n + m)**，具体分析：

​	1.	**计算 next 数组的时间复杂度**：

​	•	由于 next 数组的计算只遍历一次 pattern，所以是 **O(m)**。

​	2.	**匹配 text 的时间复杂度**：

​	•	i 遍历 text，每个 j 只前进或回溯，仍是 **O(n)**。



因此，整个算法的时间复杂度是 **O(n + m)**，比暴力匹配的 **O(n × m)** 更高效。

**4. KMP 相比暴力匹配的优势**

| **方案**     | **时间复杂度** | **适用场景**   | **主要优化点**                 |
| ------------ | -------------- | -------------- | ------------------------------ |
| **暴力匹配** | O(n × m)       | 短字符串匹配   | 无优化，直接逐个比较           |
| **KMP**      | O(n + m)       | 适合长文本搜索 | 通过 next 数组减少不必要的回溯 |

**5. 代码优化建议**

​	1.	**使用 vector<int> 替代 int next[m]**：

​	•	避免数组大小依赖编译器（动态分配更安全）。

​	2.	**封装 getNext 函数**：

​	•	将 next 数组计算独立出来，提升代码可读性。



优化版：

```
#include <iostream>
#include <vector>
using namespace std;

vector<int> getNext(const string& pattern) {
    int m = pattern.length();
    vector<int> next(m, -1);
    int j = -1;
    for (int i = 1; i < m; ++i) {
        while (j != -1 && pattern[i] != pattern[j + 1]) {
            j = next[j];
        }
        if (pattern[i] == pattern[j + 1]) {
            ++j;
        }
        next[i] = j;
    }
    return next;
}
```

**6. 总结**

​	•	**KMP 通过 next 数组减少回溯，提高匹配效率**。

​	•	**时间复杂度为 O(n + m)，适用于长文本搜索**。

​	•	**核心逻辑：**

​	•	预处理 pattern 计算 next 数组。

​	•	在 text 中进行匹配时，利用 next 数组减少重复计算。