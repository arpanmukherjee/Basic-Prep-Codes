#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int vis[MAX];
int V, E;
vector<int> adj[MAX];

bool isCyclic(int u)
{
    vis[u] = 1;
    int i, v;
    bool flag = true;
    for(i = 0 ; i < adj[u].size() ; i++)
    {
        v = adj[u][i];
        if(vis[v] == 1)
            return false;
        else if(vis[v] == 2)
            continue;
        flag &= isCyclic(v);
    }
    vis[u] = 2;
    return flag;
}

int main()
{
    int x, y, i;
    bool cycle = true;
    memset(vis, 0, sizeof(vis));

    cout << "Enter the no of Nodes";
    cin >> V;
    cout << "Enter the no of Edges";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y;          // Edge is betweene x -> y
        adj[x].push_back(y);
    }
    for(i = 0 ; i < V ; i++)
    {
        if(vis[i] == 0)
            cycle &= isCyclic(i);
    }
    if(!cycle)
        cout << "The Graph is cyclic" << endl;
    else
        cout << "The Graph is not cyclic" << endl;
    return 0;
}