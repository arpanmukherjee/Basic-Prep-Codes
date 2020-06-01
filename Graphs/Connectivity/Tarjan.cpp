// Implementation of Tarjan's algorithm to find Articulation Point/ Cut Vertices
//
// Running time: O(V+E)

#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

int V, E;
int tin[N];             // tin[i] := in time for ith node
int low[N];             // low[i] := low value of ith node
bool vis[N];            // vis[i] := ith node is visited or not
bool articulation[N];   // articulation[i] := ith node is articulation point or not
vector<int> adj[N];     // Adjacency List of the Graph

void dfs(int u, int par = -1, int timer = 0) {
    vis[u] = true;
    low[u] = tin[u] = timer;
    int n_child = 0;
    for(int v: adj[u]) {
        if(v == par)
            continue;
        if(vis[v])
            low[u] = min(low[u], tin[v]);       // direct back edge
        else {
            n_child++;
            dfs(v, u, timer + 1);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tin[u] and par != -1)  // it is an articulation point
                articulation[u] = true;
        }
    }
    if(par == -1 and n_child > 1)               // root having more than 1 children
        articulation[u] = true;
}

void Tarjan() {
    memset(vis, false, sizeof(vis));
    memset(articulation, false, sizeof(articulation));
    for(int i = 1 ; i <= V ; i++) {
        if(!vis[i])
            dfs(i);
    }
}

int32_t main() {
    int i, x, y;
    cout << "Enter the no of Nodes: ";
    cin >> V;
    cout << "Enter the no of Edges: ";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y;      // There exists an edge x - y
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    Tarjan();
    cout << "Following are the articulation point: ";
    for(i = 1 ; i <= V ; i++)
        if(articulation[i])
            cout << i << " ";
    cout << endl;
    return 0;
}