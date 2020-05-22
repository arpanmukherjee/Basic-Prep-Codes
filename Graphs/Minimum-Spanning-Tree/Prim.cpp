// Implementation of Prim's algorithm using priority queue
//
// Running time: O((E + V)logV)

#include<bits/stdc++.h>
using namespace std;

#define INF     1LL<<60
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

int V, E;
bool vis[N];
int parent[N];
vector<pii> adj[N];

void Prim(int src) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int i, u, v, wt, cost;
    for(i = 1 ; i <= V ; i++) {
        vis[i] = false;
        parent[i] = -1;
    }
    cost = 0;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        wt = pq.top().first;
        u = pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        cost += wt;
        pq.pop();
        for(i = 0 ; i < adj[u].size() ; i++) {
            v = adj[u][i].second;
            if(!vis[v])
                pq.push(adj[u][i]);
        }
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
        cin >> u >> v >> wt;    // An edge between u - v with cost wt
        adj[u].push_back(make_pair(wt, v));
        adj[v].push_back(make_pair(wt, u));
    }
    Prim(1);    // Considering 1 as source node
    return 0;
}