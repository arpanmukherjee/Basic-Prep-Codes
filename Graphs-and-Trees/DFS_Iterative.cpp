#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

bool vis[MAX];
vector<int> adj[MAX];

int main()
{
    int V, E, x, y, i;
    stack<int> Q;
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
    Q.push(0); // considering 0 as starting node
    while (!Q.empty())
    {
        x = Q.top();
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
    return 0;
}