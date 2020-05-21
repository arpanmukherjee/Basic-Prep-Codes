// Implementation of Union Find / Union by rank
//
// Running Time Complexity
// Initialize : O(N)
// Query : O(α(n)) , where α(n) is the inverse Ackermann function


#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;


int V;
int A[N], sz[N];

void initialize(int N)
{
    for (int i = 1; i <= N; i++)
    {
        A[i] = i;
        sz[i] = 1;
    }
}

int get_parent(int node)
{
    if(A[node] != node)
        A[node] = get_parent(A[node]);
    return A[node];
}

void merge(int u, int v)
{
    int root_u = get_parent(u);
    int root_v = get_parent(v);
    if(sz[root_u] < sz[root_v])
    {
        A[root_u] = root_v;
        sz[root_v] += sz[root_u];
    }
    else
    {
        A[root_v] = root_u;
        sz[root_u] += sz[root_v];
    }
}

int32_t main()
{
    int Q, type, u, v;
    cout << "Enter the no of elements:";
    cin >> V;
    initialize(V);
    cout << "Enter the no of queries:";
    cin >> Q;
    while (Q--)
    {
        cin >> type >> u >> v;
        if(type == 1)           // Merge 2 nodes, u and v
        {
            merge(u, v);
            cout << "Merged " << u << " and " << v << endl;
        }
        else if(type == 2)      // Check if u and v are connected or not
        {
            if(get_parent(u) == get_parent(v))
                cout << "Node " << u << " and " << v << " are connected";
            else
                cout << "Node " << u << " and " << v << " are  not connected";
        }
    }
    return 0;
}