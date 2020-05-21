// Implementation of Shortest path using BFS
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
int dist[N];
vector<int> adj[N];

void bfsShortestPath(int src)
{
    int i, x, y;
    queue<int> Q;
    Q.push(src);
    dist[src] = 0;
    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();
        vis[x] = true;
        for(i = 0 ; i < adj[x].size() ; i++)
        {
            y = adj[x][i];
            if(!vis[y])
            {
                Q.push(y);
                dist[y] = min(dist[y], dist[x] + 1);
            }
        }
    }
    cout << "Distance from the source node " << src << endl;
    for(i = 0 ; i < V ; i++)
        cout << i << "\t" << dist[i] << endl;
}

int32_t main()
{
    int x, y, i, src;
    memset(dist, INF, sizeof(dist));
    memset(vis, false, sizeof(vis));

    cout << "Enter the no of Nodes";
    cin >> V;
    cout << "Enter the no of Edges";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "Enter the source node:";
    cin >> src;
    bfsShortestPath(src);
    return 0;
}