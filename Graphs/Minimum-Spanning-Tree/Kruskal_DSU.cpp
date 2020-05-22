// Implementation of Kruskal's algorithm using Union Find and priority queue.
//
// Running time: O(ElogV + V + E) = O(ElogV)

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

int V, E, A[N], sz[N];
priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > edges;  // Can be used set also

void initialize(int N)
{
    for (int i = 1; i <= N; i++)
    {
        A[i] = i;
        sz[i] = 1;
    }
}

int get_parent(int node)
{
    if(A[node] != node)
        A[node] = get_parent(A[node]);
    return A[node];
}

void merge(int u, int v)
{
    int root_u = get_parent(u);
    int root_v = get_parent(v);
    if(sz[root_u] < sz[root_v])
    {
        A[root_u] = root_v;
        sz[root_v] += sz[root_u];
    }
    else
    {
        A[root_v] = root_u;
        sz[root_u] += sz[root_v];
    }
}

void Kruskal() {
    initialize(V);      // initialize each node as single component
    int u, v, wt, cost, n_edges;
    cost = n_edges = 0;
    while(!edges.empty() or n_edges < V-1) {
        wt = edges.top().first;
        u = edges.top().second.first;
        v = edges.top().second.second;
        edges.pop();
        if(get_parent(u) == get_parent(v))  // Creating a cycle
            continue;
        n_edges++;
        cost += wt;
        merge(u, v);
    }
    cout << "Total cost of the MST: " << cost << endl;
}

int32_t main() {
    int i, u, v, wt;
    cout << "Enter no of vertices:";
    cin >> V;
    cout << "Enter the no of edges:";
    cin >> E;
    for(i = 0 ; i < E ; i ++) {
        cin >> u >> v >> wt;    // An edge u -> v with cost wt
        edges.push(make_pair(wt, make_pair(u, v)));
    }
    Kruskal();
    return 0;
}
