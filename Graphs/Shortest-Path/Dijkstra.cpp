// Implementation of Dijkstra's algorithm using adjacency lists
// and priority queue for efficiency.
//
// Running time: O(|E| log |V|)

#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define INF 0x3f3f3f3f
#define pii pair<int, int>

bool vis[MAX];
int dist[MAX];
vector<pii> adj[MAX];
int V, E;

void Dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int i, u, v, wt;
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    while (!pq.empty())
    {
        u = pq.top().first;
        vis[u] = true;
        pq.pop();

        for(i = 0 ; i < adj[u].size() ; i++)
        {
            v = adj[u][i].first;
            wt = adj[u][i].second;
            if(!vis[v] and dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                vis[v] = true;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
    cout << "Distance from Source" << endl;
    for(i = 0 ; i < V ; i++)
        cout << i << "\t" << dist[v] << endl;
}

int main()
{
    int x, y, wt, src, i;
    memset(vis, false, sizeof(vis));

    cout << "Enter the no of Nodes";
    cin >> V;
    cout << "Enter the no of Edges";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y >> wt;
        adj[x].push_back(make_pair(y, wt));
        adj[y].push_back(make_pair(x, wt));
    }
    cout << "Enter the source node";
    cin >> src;
    Dijkstra(src);
    return 0;
}