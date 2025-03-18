#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

//图
//邻接矩阵存储
struct MGraph
{
    char* vexs; //顶点表
    int** arc; //邻接矩阵
    int numVertexes, numEdges; //顶点数和边数
};



//邻接表存储
struct ArcNode//边表结点
{
    int adjvex; //该弧所指向的顶点的位置
    ArcNode* nextarc; //指向下一条弧的指针
    int info; //相关信息
};
struct VNode//顶点表结点
{
    char data; //顶点信息
    ArcNode* firstarc; //指向第一条依附该顶点的弧
};
struct ALGraph
{
    VNode* adjList; //邻接表
    int numVertexes, numEdges; //顶点数和边数
};



//十字链表存储（有向图）
struct CLArcNode//弧结点
{
    int tailvex, headvex; //该弧的尾和头顶点的位置
    CLArcNode *tlink, *hlink; //分别指向弧头相同和弧尾相同的下一条弧
    int info; //该弧相关信息的指针，如权值
};
struct CLVNode//顶点表结点
{
    char data; //顶点信息
    CLArcNode *firstin, *firstout; //指向第一条入弧和出弧
};
struct CLGraph
{
    CLVNode* adjList; //邻接表
    int numVertexes, numEdges; //顶点数和边数
};



//邻接多重表存储（无向图）
struct EBox//边表结点
{
    int ivex, jvex; //该边依附的两个顶点
    EBox *ilink, *jlink; //分别指向依附这两个顶点的下一条边
    int info; //相关信息，如权值
};
struct VexBox//顶点表结点
{
    char data; //顶点信息
    EBox* firstedge; //指向第一条依附该顶点的边
};
struct AMLGraph
{
    VexBox* adjList; //邻接表
    int numVertexes, numEdges; //顶点数和边数
};



//图的遍历
//广度优先遍历
void BFSTraverse_Matrix(MGraph G)
{
    queue<int> Q;
    vector<bool> visited(G.numVertexes, false);

    for(int i = 0; i < G.numVertexes; i++)
    {
        if(!visited[i])//未访问过的顶点
        {
            visited[i] = true;
            cout << G.vexs[i] << " ";
            Q.push(i);
            while(!Q.empty())
            {
                i = Q.front();
                Q.pop();
                for(int j = 0; j < G.numVertexes; j++)
                {
                    if(G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j] = true;
                        cout << G.vexs[j] << " ";
                        Q.push(j);
                    }
                }
            }
        }
    }
}

void BFSTraverse_List(ALGraph G)
{
    queue<int> Q;
    vector<bool> visited(G.numVertexes, false);

    for(int i = 0; i < G.numVertexes; i++)
    {
        if(!visited[i])//未访问过的顶点
        {
            visited[i] = true;
            cout << G.adjList[i].data << " ";
            Q.push(i);
            while(!Q.empty())
            {
                i = Q.front();
                Q.pop();
                ArcNode* p = G.adjList[i].firstarc;
                while(p != nullptr)
                {
                    if(!visited[p->adjvex])//未访问过的顶点
                    {
                        visited[p->adjvex] = true;
                        cout << G.adjList[p->adjvex].data << " ";
                        Q.push(p->adjvex);
                    }
                    p = p->nextarc;
                }
            }
        }
    }
}



//深度优先遍历
void DFS_Matrix(MGraph G, int i, vector<bool>& visited)
{
    visited[i] = true;
    cout << G.vexs[i] << " ";
    for(int j = 0; j < G.numVertexes; j++)
    {
        if(G.arc[i][j] == 1 && !visited[j])//存在边且未访问过
        {
            DFS_Matrix(G, j, visited);
        }
    }
}
void DFSTraverse_Matrix(MGraph G)
{
    vector<bool> visited(G.numVertexes, false);
    for(int i = 0; i < G.numVertexes; i++)
    {
        if(!visited[i])
        {
            DFS_Matrix(G, i, visited);
        }
    }
}


void DFS_List(ALGraph G, int i, vector<bool>& visited)
{
    visited[i] = true;
    cout << G.adjList[i].data << " ";
    ArcNode* p = G.adjList[i].firstarc;
    while(p != nullptr)
    {
        if(!visited[p->adjvex])//未访问过的顶点
        {
            DFS_List(G, p->adjvex, visited);
        }
        p = p->nextarc;
    }
}
void DFSTraverse_List(ALGraph G)
{
    vector<bool> visited(G.numVertexes, false);
    for(int i = 0; i < G.numVertexes; i++)
    {
        if(!visited[i])
        {
            DFS_List(G, i, visited);
        }
    }
}



//最小生成树
//Prim普里姆算法:
//从一个顶点出发，每次找到与当前生成树相邻的最短边，加入生成树，直到所有顶点都加入生成树，生成最小生成树
//时间复杂度：O(｜V｜^2)，空间复杂度：O(n)，适合稠密图
void MiniSpanTree_Prim_Matrix(MGraph G)
{
    vector<bool> intree(G.numVertexes, false); // 记录节点是否在树中
    vector<int> lowcost(G.numVertexes, INT_MAX); // 保存相关顶点间边的权值
    lowcost[0] = 0; // 初始化第一个权值为0，即v0加入生成树

    for(int i = 0; i < G.numVertexes; i++)
    {
        int min = INT_MAX;
        int k = -1;// 保存最小权值的顶点

        // 找到不在树中且权值最小的顶点
        for(int j = 0; j < G.numVertexes; j++)
        {
            if(!intree[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }

        if(k == -1) break; // 如果没有找到这样的顶点，退出循环

        intree[k] = true; // 将该顶点加入生成树
        cout << k << " "; // 输出当前顶点

        // 更新lowcost数组，以k为中间点，更新v0到未加入生成树顶点的权值
        for(int j = 0; j < G.numVertexes; j++)
        {
            if(!intree[j] && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
            }
        }
    }
}


void MiniSpanTree_Prim_List(ALGraph G)
{
    vector<bool> intree(G.numVertexes, false); // 记录节点是否在树中
    vector<int> lowcost(G.numVertexes, INT_MAX); // 保存相关顶点间边的权值
    lowcost[0] = 0; // 初始化第一个权值为0，即v0加入生成树

    ArcNode* p = G.adjList[0].firstarc;
    while(p != nullptr)
    {
        lowcost[p->adjvex] = p->info;
        p = p->nextarc;
    }

    for(int i = 0; i < G.numVertexes; i++)
    {
        int min = INT_MAX;
        int k = -1;

        // 找到不在树中且权值最小的顶点
        for(int j = 0; j < G.numVertexes; j++)
        {
            if(!intree[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }

        if(k == -1) break; // 如果没有找到这样的顶点，退出循环

        intree[k] = true; // 将该顶点加入生成树
        cout << k << " "; // 输出当前顶点

        // 更新lowcost数组，以k为中间点，更新v0到未加入生成树顶点的权值
        p = G.adjList[k].firstarc;
        while(p != nullptr)
        {
            if(!intree[p->adjvex] && p->info < lowcost[p->adjvex])
            {
                lowcost[p->adjvex] = p->info;
            }
            p = p->nextarc;
        }
    }
}



//Kruskal算法:
//将所有边按权值从小到大排序，依次加入生成树，直到所有顶点都加入生成树，生成最小生成树
//时间复杂度：O(｜E｜log｜E｜)，空间复杂度：O(n)，适合稀疏图
//注意：Kruskal算法需要使用并查集来判断是否形成回路
//并查集
struct DisjointSet
{
    int* parent;//父节点
    int* rank;//秩，用于优化，防止树的高度过高
    int size;//集合大小

    DisjointSet(int n)
    {
        size = n;
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~DisjointSet()
    {
        delete[] parent;
        delete[] rank;
    }

    int find(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)
        {
            if(rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if(rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
struct Edge
{
    int start, end, weight;
};
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void MiniSpanTree_Kruskal_Matrix(MGraph G)
{
    DisjointSet ds(G.numVertexes);
    vector<Edge> edges;
    for(int i = 0; i < G.numVertexes; i++)
    {
        for(int j = i + 1; j < G.numVertexes; j++)
        {
            if(G.arc[i][j] != 0)
            {
                edges.push_back({i, j, G.arc[i][j]});
            }
        }
    }

    sort(edges.begin(), edges.end(), compare);

    for(auto edge : edges)
    {
        if(ds.find(edge.start) != ds.find(edge.end))
        {
            ds.unionSet(edge.start, edge.end);
            cout << edge.start << " " << edge.end << " " << edge.weight << endl;
        }
    }
}

void MiniSpanTree_Kruskal_List(ALGraph G)
{
    DisjointSet ds(G.numVertexes);
    vector<Edge> edges;
    for(int i = 0; i < G.numVertexes; i++)
    {
        ArcNode* p = G.adjList[i].firstarc;
        while(p != nullptr)
        {
            if(i < p->adjvex)//避免重复添加边
            {
                edges.push_back({i, p->adjvex, p->info});
            }
            p = p->nextarc;
        }
    }

    sort(edges.begin(), edges.end(), compare);

    for(auto edge : edges)
    {
        if(ds.find(edge.start) != ds.find(edge.end))
        {
            ds.unionSet(edge.start, edge.end);
            cout << edge.start << " " << edge.end << " " << edge.weight << endl;
        }
    }
}



//最短路径算法
//单源最短路径
//BFS算法（无权图），时间复杂度：O(｜V｜^2)
void ShortestPath_BFS_Matrix(MGraph G, int start)
{
    vector<int> dist(G.numVertexes, INT_MAX);//初始化距离为无穷大
    vector<bool> visited(G.numVertexes, false);
    queue<int> Q;

    dist[start] = 0;
    visited[start] = true;
    Q.push(start);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int v = 0; v < G.numVertexes; v++)
        {
            if(G.arc[u][v] == 1 && !visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }

    for(int i = 0; i < G.numVertexes; i++)
    {
        cout << "从" << G.vexs[start] << "到" << G.vexs[i] << "的最短路径长度为：" << dist[i] << endl;
    }
}

//时间复杂度：O(｜V｜+｜E｜)
void ShortestPath_BFS_List(ALGraph G, int start)
{
    vector<int> dist(G.numVertexes, INT_MAX);
    vector<bool> visited(G.numVertexes, false);
    queue<int> Q;

    dist[start] = 0;
    visited[start] = true;
    Q.push(start);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        ArcNode* p = G.adjList[u].firstarc;
        while(p != nullptr)
        {
            if(!visited[p->adjvex])
            {
                visited[p->adjvex] = true;
                dist[p->adjvex] = dist[u] + 1;
                Q.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }

    for(int i = 0; i < G.numVertexes; i++)
    {
        cout << "从" << G.adjList[start].data << "到" << G.adjList[i].data << "的最短路径长度为：" << dist[i] << endl;
    }
}


//Dijkstra算法（有权图、无权图）
//时间复杂度：O(｜V｜^2)，空间复杂度：O(n)
void Dijkstra_Matrix(MGraph G, int start)
{
    vector<int> dist(G.numVertexes, INT_MAX);
    vector<bool> visited(G.numVertexes, false);
    dist[start] = 0;

    for(int i = 0; i < G.numVertexes; i++)
    {
        int u = -1;
        int minDist = INT_MAX;
        for(int j = 0; j < G.numVertexes; j++)
        {
            if(!visited[j] && dist[j] < minDist)
            {
                u = j;
                minDist = dist[j];
            }
        }

        if(u == -1) break;//没有找到这样的顶点，退出循环

        visited[u] = true;
        //更新dist数组，以u为中间点，更新start到未加入生成树顶点的权值
        for(int v = 0; v < G.numVertexes; v++)
        {
            if(G.arc[u][v] != 0 && !visited[v])
            {
                dist[v] = min(dist[v], dist[u] + G.arc[u][v]);
            }
        }
    }

    for(int i = 0; i < G.numVertexes; i++)
    {
        cout << "从" << G.vexs[start] << "到" << G.vexs[i] << "的最短路径长度为：" << dist[i] << endl;
    }
}

void Dijkstra_List(ALGraph G, int start)
{
    vector<int> dist(G.numVertexes, INT_MAX);
    vector<bool> visited(G.numVertexes, false);
    dist[start] = 0;

    for(int i = 0; i < G.numVertexes; i++)
    {
        int u = -1;
        int minDist = INT_MAX;
        for(int j = 0; j < G.numVertexes; j++)
        {
            if(!visited[j] && dist[j] < minDist)
            {
                u = j;
                minDist = dist[j];
            }
        }

        if(u == -1) break;

        visited[u] = true;

        ArcNode* p = G.adjList[u].firstarc;
        while(p != nullptr)
        {
            if(!visited[p->adjvex] && p->info >= 0) // 检查边的权值是否为非负数
            {
                dist[p->adjvex] = min(dist[p->adjvex], dist[u] + p->info);
            }
            p = p->nextarc;
        }
    }

    for(int i = 0; i < G.numVertexes; i++)
    {
        cout << "从" << G.adjList[start].data << "到" << G.adjList[i].data << "的最短路径长度为：" << dist[i] << endl;
    }
}



//Floyd算法（有权图、无权图）
//时间复杂度：O(｜V｜^3)，空间复杂度：O(n^2)
void Floyd_Matrix(MGraph G)
{
    vector<vector<int>> dist(G.numVertexes, vector<int>(G.numVertexes, INT_MAX));

    // 初始化距离矩阵：
    // 若 i==j，则设为 0；
    // 若 G.arc[i][j] == 0 且 i != j 则认为无边，设为 INT_MAX；
    // 否则使用 G.arc[i][j] 的权值
    for (int i = 0; i < G.numVertexes; i++)
    {
        for (int j = 0; j < G.numVertexes; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (G.arc[i][j] == 0)
                dist[i][j] = INT_MAX;
            else
                dist[i][j] = G.arc[i][j];
        }
    }

    // 开始 Floyd 松弛操作
    for (int k = 0; k < G.numVertexes; k++)
    {
        for (int i = 0; i < G.numVertexes; i++)
        {
            for (int j = 0; j < G.numVertexes; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 输出结果
    for (int i = 0; i < G.numVertexes; i++)
    {
        for (int j = 0; j < G.numVertexes; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << "从" << G.vexs[i] << "到" << G.vexs[j] << "无路径" << endl;
            else
                cout << "从" << G.vexs[i] << "到" << G.vexs[j] << "的最短路径长度为：" << dist[i][j] << endl;
        }
    }
}

//时间复杂度：O(｜V｜^3)，空间复杂度：O(n^2)
void Floyd_List(ALGraph G)
{
    // 初始化距离矩阵：对角线为0，其余为无穷大
    vector<vector<int>> dist(G.numVertexes, vector<int>(G.numVertexes, INT_MAX));
    for (int i = 0; i < G.numVertexes; i++)
    {
        for (int j = 0; j < G.numVertexes; j++)
        {
            dist[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    // 根据邻接表初始化边权，若存在多条边则取较小的权值
    for (int i = 0; i < G.numVertexes; i++)
    {
        ArcNode* p = G.adjList[i].firstarc;
        while (p != nullptr)
        {
            dist[i][p->adjvex] = min(dist[i][p->adjvex], p->info);
            p = p->nextarc;
        }
    }

    // Floyd 松弛操作：对所有点作为中间点进行松弛
    for (int k = 0; k < G.numVertexes; k++)
    {
        for (int i = 0; i < G.numVertexes; i++)
        {
            for (int j = 0; j < G.numVertexes; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 输出最短路径结果：若为无穷大则输出“无路径”
    for (int i = 0; i < G.numVertexes; i++)
    {
        for (int j = 0; j < G.numVertexes; j++)
        {
            cout << "从" << G.adjList[i].data << "到" << G.adjList[j].data << "的最短路径长度为：";
            if (dist[i][j] == INT_MAX)
                cout << "无路径";
            else
                cout << dist[i][j];
            cout << endl;
        }
    }
}



//拓扑排序
//时间复杂度：O(｜V｜+｜E｜)，空间复杂度：O(n)
void TopologicalSort_Matrix(MGraph G)
{
    vector<int> indegree(G.numVertexes, 0);
    //初始化入度数组
    for (int i = 0; i < G.numVertexes; i++)
    {
        for (int j = 0; j < G.numVertexes; j++)
        {
            if (G.arc[i][j] != 0)
            {
                indegree[j]++;
            }
        }
    }
    //入度为0的顶点入队
    queue<int> Q;
    for (int i = 0; i < G.numVertexes; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
        }
    }
    //不断找到入度为0的顶点，输出并删除该顶点
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << G.vexs[u] << " ";
        for (int v = 0; v < G.numVertexes; v++)
        {
            if (G.arc[u][v] != 0)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    Q.push(v);
                }
            }
        }
    }
}

void TopologicalSort_List(ALGraph G)
{
    vector<int> indegree(G.numVertexes, 0);
    for (int i = 0; i < G.numVertexes; i++)
    {
        ArcNode* p = G.adjList[i].firstarc;
        while (p != nullptr)
        {
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }
    //入度为0的顶点入队
    queue<int> Q;
    for (int i = 0; i < G.numVertexes; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
        }
    }
    //不断找到入度为0的顶点，输出并删除该顶点
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << G.adjList[u].data << " ";
        ArcNode* p = G.adjList[u].firstarc;
        while (p != nullptr)
        {
            indegree[p->adjvex]--;
            if (indegree[p->adjvex] == 0)
            {
                Q.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
}

//拓扑排序-DFS实现
void TopologicalSort_DFS_Matrix(MGraph G, int i, vector<bool>& visited, vector<int>& result)
{
    visited[i] = true;
    for (int j = 0; j < G.numVertexes; j++)
    {
        if (G.arc[i][j] != 0 && !visited[j])
        {
            TopologicalSort_DFS_Matrix(G, j, visited, result);
        }
    }
    result.push_back(i);
}

void TopologicalSort_DFS_Matrix(MGraph G)
{
    vector<bool> visited(G.numVertexes, false);
    vector<int> result;

    for (int i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            TopologicalSort_DFS_Matrix(G, i, visited, result);
        }
    }

    // 输出结果
    reverse(result.begin(), result.end());
    for (int i : result)
    {
        cout << G.vexs[i] << " ";
    }
}


void TopologicalSort_DFS_List(ALGraph G, int i, vector<bool>& visited, vector<int>& result)
{
    visited[i] = true;
    ArcNode* p = G.adjList[i].firstarc;
    while (p != nullptr)
    {
        if (!visited[p->adjvex])
        {
            TopologicalSort_DFS_List(G, p->adjvex, visited, result);
        }
        p = p->nextarc;
    }
    result.push_back(i);
}

void TopologicalSort_DFS_List(ALGraph G)
{
    vector<bool> visited(G.numVertexes, false);
    vector<int> result;

    for (int i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            TopologicalSort_DFS_List(G, i, visited, result);
        }
    }

    // 输出结果
    reverse(result.begin(), result.end());
    for (int i : result)
    {
        cout << G.adjList[i].data << " ";
    }
}



int main() {
    //邻接矩阵
    MGraph G;
    G.numVertexes = 5;
    G.numEdges = 5;
    G.vexs = new char[G.numVertexes];
    G.arc = new int*[G.numVertexes];
    for(int i = 0; i < G.numVertexes; i++)
    {
        G.arc[i] = new int[G.numVertexes];//二维数组
    }
    for(int i = 0; i < G.numVertexes; i++)//初始化邻接矩阵
    {
        for(int j = 0; j < G.numVertexes; j++)
        {
            G.arc[i][j] = 0;
        }
    }
    G.vexs[0] = 'A';
    G.vexs[1] = 'B';
    G.vexs[2] = 'C';
    G.vexs[3] = 'D';
    G.vexs[4] = 'E';
    G.arc[0][1] = 1;
    G.arc[0][2] = 1;
    G.arc[1][3] = 1;
    G.arc[1][4] = 1;
    G.arc[2][4] = 1;
    G.arc[3][4] = 1;

    cout<<"邻接矩阵存储的图的广度优先遍历结果："<<endl;
    BFSTraverse_Matrix(G);
    cout<<endl;
    cout<<"邻接矩阵存储的图的深度优先遍历结果："<<endl;
    DFSTraverse_Matrix(G);
    cout<<endl;
    cout<<"Prim算法生成的最小生成树："<<endl;
    MiniSpanTree_Prim_Matrix(G);
    cout<<endl;
    cout<<"Kruskal算法生成的最小生成树："<<endl;
    MiniSpanTree_Kruskal_Matrix(G);
    cout<<"最短路径（BFS算法）结果："<<endl;
    ShortestPath_BFS_Matrix(G, 0);
    cout<<"最短路径（Dijkstra算法）结果："<<endl;
    Dijkstra_Matrix(G, 0);
    cout<<"Floyd算法生成的最短路径结果："<<endl;
    Floyd_Matrix(G);
    cout<<endl;

    //邻接表
    ALGraph G2;
    G2.numVertexes = 5;
    G2.numEdges = 5;
    G2.adjList = new VNode[G2.numVertexes];//顶点表
    for(int i = 0; i < G2.numVertexes; i++)//初始化顶点表
    {
        G2.adjList[i].data = G.vexs[i];
        G2.adjList[i].firstarc = nullptr;
    }
    ArcNode* p;
    for(int i = 0; i < G2.numVertexes; i++)//初始化邻接表
    {
        for(int j = 0; j < G2.numVertexes; j++)
        {
            if(G.arc[i][j] == 1)
            {
                p = new ArcNode;
                p->adjvex = j;
                p->info = 1;
                p->nextarc = G2.adjList[i].firstarc;
                G2.adjList[i].firstarc = p;
            }
        }
    }

    cout<<"邻接表存储的图的广度优先遍历结果："<<endl;
    BFSTraverse_List(G2);
    cout<<endl;
    cout<<"邻接表存储的图的深度优先遍历结果："<<endl;
    DFSTraverse_List(G2);
    cout<<endl;
    cout<<"Prim算法生成的最小生成树："<<endl;
    MiniSpanTree_Prim_List(G2);
    cout<<endl;
    cout<<"Kruskal算法生成的最小生成树："<<endl;
    MiniSpanTree_Kruskal_List(G2);
    cout<<"最短路径（BFS算法）结果："<<endl;
    ShortestPath_BFS_List(G2, 0);
    cout<<"最短路径（Dijkstra算法）结果："<<endl;
    Dijkstra_List(G2, 0);
    cout<<"Floyd算法生成的最短路径结果："<<endl;
    Floyd_List(G2);
    cout<<endl;

    //构造有向无环图的邻接矩阵
    MGraph G3;
    G3.numVertexes = 5;
    G3.numEdges = 5;
    G3.vexs = new char[G3.numVertexes];
    G3.arc = new int*[G3.numVertexes];
    for(int i = 0; i < G3.numVertexes; i++)
    {
        G3.arc[i] = new int[G3.numVertexes];//二维数组
    }
    for(int i = 0; i < G3.numVertexes; i++)//初始化邻接矩阵
    {
        for(int j = 0; j < G3.numVertexes; j++)
        {
            G3.arc[i][j] = 0;
        }
    }
    G3.vexs[0] = 'A';
    G3.vexs[1] = 'B';
    G3.vexs[2] = 'C';
    G3.vexs[3] = 'D';
    G3.vexs[4] = 'E';
    G3.arc[0][1] = 1;
    G3.arc[0][2] = 1;
    G3.arc[1][3] = 1;
    G3.arc[1][4] = 1;
    G3.arc[2][4] = 1;
    G3.arc[3][4] = 1;
    cout<<"拓扑排序结果："<<endl;
    TopologicalSort_Matrix(G3);
    cout<<endl;

    return 0;
}