#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

bool vis[MAX];
vector<int> adj[MAX];

void dfsIterative(int u)
{
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

int main()
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
    return 0;
}