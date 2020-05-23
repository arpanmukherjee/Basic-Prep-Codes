// Implementation of LCA Using Binary Lifting (Sparse Table + Euler Tour)
//
// Running Time Complexity
// Build : O(NlogN)
// Range Query : O(1)


#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

int V, E;
bool vis[N];
vector<int> Euler;
vector<int> adj[N];

void eulerTree(int u) {
    vis[u] = true;
    Euler.push_back(u);
    for(int v: adj[u]) {
        if(!vis[v]) {
            eulerTree(v);
            Euler.push_back(u);
        }
    }
}

int32_t main() {
    cout << "Enter the no of vertices:";
    cin >> V;
    cout << "Enter the no of edges:";
    cin >> E;
    
    return 0;
}