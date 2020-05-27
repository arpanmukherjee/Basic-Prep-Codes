// Implementation of Topological Sorting Recursively
//
// Running Time Complexity : O(V+E)

#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

int V, E;
bool vis[N];
stack<int> nodes;
vector<int> adj[N];

void TopologicalSortRecursive(int u)
{
    vis[u] = true;
    for(int v: adj[u])
        if(!vis[v])
            TopologicalSortRecursive(v);
    nodes.push(u);
}

int32_t main()
{
    int u, v, i;
    memset(vis, false, sizeof(vis));

    cout << "Enter the no of Nodes";
    cin >> V;
    cout << "Enter the no of Edges";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> u >> v;          // There's an edge u -> v
        adj[u].push_back(v);
    }
    for(u = 1 ; u <= V ; u++) {
        if(!vis[u])
            TopologicalSortRecursive(u);
    }
    cout << "Topological Sorting: \n";
    while(!nodes.empty()) {
        cout << nodes.top() << " ";
        nodes.pop();
    }
    cout << endl;
    return 0;
}