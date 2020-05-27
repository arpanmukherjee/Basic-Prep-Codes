// Implementation of Dijkstra's algorithm using adjacency lists and priority queue.
//
// Running time: O(ElogV)

#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

bool vis[N];                        // vis[i] := ith node is visited or not
stack<int> st;                      // stack to keep track of traversal
vector<int> adj[N];                 // Actual Graph
vector<int> reverseAdj[N];          // Reverse Graph
vector<int>components[N];           // Strongly Connected Components
int V, E;

void dfs1(int u) {
    vis[u] = true;
    for(int v: adj[u]) {
        if(!vis[v])
            dfs1(v);
    }
    st.push(u);
}

void dfs2(int u, int ind) {
    vis[u] = true;
    components[ind].push_back(u);
    for(int v: reverseAdj[u]) {
        if(!vis[v])
            dfs2(v, ind);
    }
}

void Kosaraju() {
    int i, u, n_comp;
    memset(vis, false, sizeof(vis));
    for(i = 1 ; i <= V ; i++) {
        if(!vis[i])
            dfs1(i);
    }
    n_comp = 0;
    memset(vis, false, sizeof(vis));
    while(!st.empty()) {
        u = st.top();
        st.pop();
        if(!vis[u]) {
            n_comp++;
            dfs2(u, n_comp);
        }
    }
    cout << "No of strongly connected components are: " << n_comp << endl;
    for(i = 1 ; i <= n_comp ; i++) {
        cout << "Nodes of " << i << "th component: ";
        for(int v: components[i])
            cout << v << " ";
        cout << endl;
    }
}

int32_t main() {
    int i, x, y;
    cout << "Enter the no of Nodes";
    cin >> V;
    cout << "Enter the no of Edges";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        reverseAdj[y].push_back(x);
    }
    Kosaraju();

    return 0;
}