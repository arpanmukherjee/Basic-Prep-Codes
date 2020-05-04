#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

bool vis[MAX];
int V, E;
vector<int> adj[MAX];

bool isCyclic(int u, int parent)
{
    vis[u] = true;

    int i, v;
    bool flag = true;

    for(i = 0 ; i < adj[u].size() ; i++)
    {
        v = adj[u][i];
        if(!vis[v])
            flag &= isCyclic(v, u);
        else
        {
            if(v == parent)
                continue;
            else
                return false;
        }
    }
    return flag;
}

int main()
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
    if(!cycle)
        cout << "The Graph is cyclic" << endl;
    else
        cout << "The Graph is not cyclic" << endl;
    return 0;
}