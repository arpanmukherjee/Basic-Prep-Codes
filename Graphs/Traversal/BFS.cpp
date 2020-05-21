// Implementation of BFS
//
// Running Time Complexity : O(V+E)

#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

bool vis[N];
vector<int> adj[N];

void bfs(int src)
{
    int i, x, y;
    queue<int> Q;
    Q.push(src);
    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();
        vis[x] = true;
        for(i = 0 ; i < adj[x].size() ; i++)
        {
            y = adj[x][i];
            if(!vis[y])
                Q.push(y);
        }
        cout << x << " ";
    }
}

int32_t main()
{
    int V, E, x, y, i;
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
    bfs(0);
    return 0;
}