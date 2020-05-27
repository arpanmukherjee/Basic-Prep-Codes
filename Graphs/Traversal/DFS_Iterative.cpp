// Implementation of DFS Iteratively
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
vector<int> adj[N];

void dfsIterative(int u)
{
    memset(vis, false, sizeof(vis));
    stack<int> st;
    int i, x, y;
    st.push(u);
    while (!st.empty())
    {
        x = st.top();
        st.pop();
        vis[x] = true;
        for(i = 0 ; i < adj[x].size() ; i++)
        {
            y = adj[x][i];
            if(!vis[y])
                st.push(y);
        }
        cout << x << " ";
    }
}

int32_t main()
{
    int x, y, i;

    cout << "Enter the no of Nodes: ";
    cin >> V;
    cout << "Enter the no of Edges: ";
    cin >> E;
    for(i = 0 ; i < E ; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    return 0;
}