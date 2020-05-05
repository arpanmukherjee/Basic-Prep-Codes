#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

bool vis[MAX];
vector<int> adj[MAX];

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

int main()
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