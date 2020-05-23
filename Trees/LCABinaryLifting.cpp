// Implementation of LCA Using Binary Lifting
//
// Running Time Complexity
// V = Vertices, E = Edges, H = Height
// Build LCA: O(V+E) + O(HlogH)
// Query LCA: O(logH)


#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;
const int LOGN = 15;


int lvl[N];         // lvl[i] := depth of node i
bool vis[N];        // vis[i] := visited status of node i
int parent[N];      // parent[i] := parent of node i
int lca[N][LOGN+1]; // lca[i][j] := 2^j th ancesstor of node i
vector<int> adj[N];
int V, E;

void dfs(int u, int par, int dep = 1) {
    lvl[u] = dep;
    parent[u] = par;
    vis[u] = true;
    for(int v: adj[u]) {
        int v = adj[u][i];
        if(!vis[v])
            dfs(v, u, dep+1);
    }
}

void buildLCA(int root) {
    int i, j;
    memset(lca, -1, sizeof(lca));
    memset(vis, false, sizeof(vis));
    dfs(root, -1);     // To get the parent of each node
    for(i = 1 ; i <= V ; i++)
        lca[i][0] = parent[i];
    for(j = 1 ; (1<<j) < V ; j++) {
        for(i = 1 ; i <= V ; i++) {
            if(lca[i][j-1] != -1)   // If node i has no (1<<j-1)th ancesstor, then it won't have (1<<j)th ancesstor as well
                lca[i][j] = lca[lca[i][j-1]][j-1];
        }
    }
}

int getLCA(int u, int v) {
    if(lvl[u] < lvl[v])
        swap(u, v);
    int diff, jump, j, LOGMAX;
    diff = lvl[u] - lvl[v];
    while(diff) {   // bring u and v at same level
        jump = log2(diff);
        u = lca[u][jump];
        diff -= (1<<jump);
    }
    if(u == v)
        return u;
    LOGMAX = log2(lvl[u]);
    for(j = LOGMAX ; j >= 0 ; j--) {  // Find the child of the LCA
        if(lca[u][j] != -1 and lca[u][j] != lca[v][j]) {
            u = lca[u][j];
            v = lca[v][j];
        }
    }
    return parent[u];
}


int32_t main() {
    int i, u, v, root;
    cout << "Enter the no of vertices:";
    cin >> V;
    cout << "Enter the no of edges:";
    cin >> E;
    for(i = 1 ; i <= V ; i++) {
        cin >> u >> v;
        adj[u].push_back(v);    // There's an edge u -> v
    }
    cout << "Enter the root of the tree";
    cin >> root;
    buildLCA(root);
    cout << "LCA of 1 and 3 is: " << getLCA(1, 3) << endl;
    return 0;
}