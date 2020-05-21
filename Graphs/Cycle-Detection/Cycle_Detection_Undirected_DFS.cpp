// Implementation of Cycle detection of Undirected graph using DFS
//
// Running Time Complexity : O(V+E)

#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

bool vis[N];
int V, E;
vector<int> adj[N];

bool isCyclic(int u, int parent)
{
    vis[u] = true;

    int i, v;
    bool flag = false;

    for(i = 0 ; i < adj[u].size() ; i++)
    {
        v = adj[u][i];
        if(!vis[v])
            flag |= isCyclic(v, u);
        else
        {
            if(v == parent)
                continue;
            else
                return true;
        }
    }
    return flag;
}

int32_t main()
{
    int x, y, i;
    bool cycle = true;
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

    for(i = 0 ; i < V ; i++)
    {
        if(vis[i] == 0)
            cycle &= isCyclic(i, -1);
    }
    if(cycle)
        cout << "The Graph is cyclic" << endl;
    else
        cout << "The Graph is not cyclic" << endl;
    return 0;
}