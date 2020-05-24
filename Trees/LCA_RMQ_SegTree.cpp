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

vector<int> EulerTour;
int F[N];       // F[i] := First occurance of node i
int tree[4*N];  // Segment tree
int node[N];    // node[i] := corresponding mapping of node i
int node_[N];   // node_[i] := corresponding inverse mapping of node i

int V, E;
bool vis[N];
vector<int> adj[N];

void buildTree(int node, int beg, int end) {
    if(beg == end) {
        tree[node] = EulerTour[beg];
        return;
    }
    int mid = (beg+end) >> 1;
    buildTree(2*node, beg, mid);
    buildTree(2*node+1, mid+1, end);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int eulerQuery(int node, int beg, int end, int l, int r) {
    if(r < beg or end < l)      // not in the range
        return INF;
    if(l <= beg and end <= r)   // completely overlaps with [beg, end]
        return tree[node];
    int mid = (beg+end) >> 1;
    int p1 = eulerQuery(2*node, beg, mid, l, r);
    int p2 = eulerQuery(2*node+1, mid+1, end, l, r);
    return min(p1, p2);
}

void dfs(int u, int& idx) {
    vis[u] = true;
    node[u] = idx;
    node_[idx] = u;
    F[u] = EulerTour.size();
    idx++;
    EulerTour.push_back(node[u]);
    for(int i = 0 ; i < adj[u].size() ; i++) {
        int v = adj[u][i];
        if(!vis[v]) {
            dfs(v, idx);
            EulerTour.push_back(node[u]);
        }
    }
}

void buildLCA(int root) {
    EulerTour.clear();
    EulerTour.push_back(0);     // To make Euler array 1-based
    memset(vis, false, sizeof(vis));
    int idx = 1;
    dfs(root, idx);
    buildTree(1, 1, EulerTour.size()-1);
}

int getLCA(int u, int v) {
    if(F[u] > F[v])
        swap(u, v);
    int ans = eulerQuery(1, 1, EulerTour.size()-1, F[u], F[v]);
    return node_[ans];
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