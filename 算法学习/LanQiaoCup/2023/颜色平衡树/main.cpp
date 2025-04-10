/*
题目描述
给定一棵树，结点由 1 至 n 编号，其中结点 1 是树根。
树的每个点有一个颜色 Ci
如果一棵树中存在的每种颜色的结点个数都相同，则我们称它是一棵颜色平衡树。
求出这棵树中有多少个子树是颜色平衡树。

输入格式
输入的第一行包含一个整数 n，表示树的结点数。

接下来 n 行，每行包含两个整数 Ci 和 Fi，用一个空格分隔，表示第 i 个结点的颜色和父亲结点编号。
保证输入数据是一棵树。

输出格式
输出一行包含一个整数表示答案。

样例输入
6
2 0
2 1
1 2
3 3
3 4
1 4
样例输出
4
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 全局变量记录颜色平衡子树数量
int balancedCount = 0;

// 判断统计表中的所有计数是否都相同
bool isBalanced(const unordered_map<int,int>& freq) {
    if(freq.empty())
        return true;
    int count = freq.begin()->second;
    for (auto &p : freq) {
        if(p.second != count)
            return false;
    }
    return true;
}

// DFS 遍历树并合并子树中颜色的统计
unordered_map<int,int> dfs(int node, const vector<int>& color, const vector<vector<int>>& children) {
    unordered_map<int,int> freq;
    // 当前节点的颜色计数加 1
    freq[color[node]] = 1;

    // 遍历所有子节点
    for (int child : children[node]) {
        unordered_map<int,int> childFreq = dfs(child, color, children);
        // 合并子节点的统计到当前节点 freq 中
        for (auto &p : childFreq) {
            freq[p.first] += p.second;
        }
    }
    // 如果当前子树的所有颜色数量均相等，则计数
    if(isBalanced(freq))
        balancedCount++;
    return freq;
}

int main(){
    int n;
    cin >> n;
    // 使用 0-base 索引保存，定义大小为 n
    vector<int> colors(n, 0);
    // 父节点以及记录孩子关系，初始化 n 个节点
    vector<vector<int>> children(n);
    int c, f;
    int root = -1;
    for (int i = 0; i < n; i++){
        cin >> c >> f;
        colors[i] = c;
        // 如果 f 为 0，表示没有父节点，认为是根节点
        if(f == 0)
            root = i;
        else{
            // f 以 1 为编号 转 0-base 索引
            children[f - 1].push_back(i);
        }
    }

    // 若未指定根节点，可在此检测，假设一定有根节点
    dfs(root, colors, children);
    cout << balancedCount << endl;
    return 0;
}