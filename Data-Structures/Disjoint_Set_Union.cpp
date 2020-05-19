#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int N;
int A[MAX], sz[MAX];

void initialize()
{
    for (int i = 0; i < N; i++)
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

int main()
{
    int Q, type, u, v;
    cout << "Enter the no of elements:";
    cin >> N;
    initialize();
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