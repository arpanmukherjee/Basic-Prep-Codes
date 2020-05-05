#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

bool vis[MAX];
int V, E;
int par[MAX], sz[MAX];
vector<int> adj[MAX];

void init_DSU()
{
    for (int i = 0; i < V; i++)
    {
        par[i] = i;         // Parent of node i
        sz[i] = 1;          // Size of node i
    }
}

int get_parent(int node)
{
    if(node != par[node])
        par[node] = get_parent(par[node]);
    return par[node];
}

void merge(int u, int v)
{
    int u_par = get_parent(u);
    int v_par = get_parent(v);
    if(sz[u_par] > sz[v_par])
    {
        par[v_par] = par[u_par];
        sz[u_par] += sz[v_par];
        sz[v_par] = 1;
    }
    else
    {
        par[u_par] = par[v_par];
        sz[v_par] += sz[u_par];
        sz[u_par] = 1;
    }
}


int main()
{
    int x, y, i, x_, y_;
    bool isCyclic = false;
    memset(vis, false, sizeof(vis));

    cout << "Enter the no of Nodes";
    cin >> V;
    init_DSU();
    cout << "Enter the no of Edges";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y;
        x_ = get_parent(x);
        y_ = get_parent(y);
        if(x_ == y_)
        {
            isCyclic = true;
            break;
        }
        merge(x, y);
    }
    if(isCyclic)
        cout << "The Graph is cyclic" << endl;
    else
        cout << "The Graph is not cyclic" << endl;
    return 0;
}