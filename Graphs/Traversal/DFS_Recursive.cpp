// Implementation of DFS Recursively
//
// Running Time Complexity : O(V+E)

#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

bool vis[N];
vector<int> adj[N];

void dfsRecursive(int u)
{
    int i, v;
    vis[u] = true;
    cout << u << " ";
    for(i = 0 ; i < adj[u].size() ; i++)
    {
        v = adj[u][i];
        if(!vis[v])
            dfsRecursive(v);
    }
}

int32_t main()
{
    int V, E, x, y, i;
    memset(vis, false, sizeof(vis));

    cout << "Enter the no of Nodes";
    cin >> V;
    cout << "Enter the no of Edges";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfsRecursive(0);
    return 0;
}