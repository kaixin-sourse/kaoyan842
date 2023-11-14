#include <bits/stdc++.h>
#define MAX_VERTEX_NUM 100
using namespace std;
typedef int VertexType;
const int N = 100010;
int color[N]; // 用于dfs判环用
typedef struct ArcNode
{
    int adjVex;
    struct ArcNode *nextArc;
    int weight;
} ArcNode;
typedef struct VNode
{
    VertexType data;
    ArcNode *firstArc;
} VNode1, AdjList[MAX_VERTEX_NUM];
typedef struct ALGraph
{
    AdjList vertices;
    int VexNum;
    int arcNum;
    int kind;
} ALGraph;
typedef struct A // 记得加typedef , 要不底下不能用AA定义
{
    int a;
} AA;
bool flag = false;
int dfs(ALGraph G, VertexType v)
{
    if (flag)
        return;
    color[v] = 0;
    ArcNode *p = G.vertices[v].firstArc;
    while (p != NULL)
    {
        VertexType w = p->adjVex;
        if (color[w] == -1)
        {
            dfs(G, w);
        }
        else if (color[w] == 0)
        {
            {
                flag = true;
                return;
            }
        }
        p = p->nextArc;
    }
    color[v] = 1;
}
int main()
{
    for (int i = 0; i < N; i++)
        color[i] = -1;
    return 0;
}
