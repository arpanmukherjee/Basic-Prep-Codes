// Implementation of Segment Tree
//
// Running Time Complexity
// Build : O(N)
// Point Update : O(log N)
// Range Query : O(log N)


#include<bits/stdc++.h>
using namespace std;

#define INF     0x3f3f3f3f
#define int     long long
#define pii     pair<int, int>

const int N = 100005;

int A[N];
int tree[4*N];  // Seg tree takes 4*N memory of the array


void build_tree(int node, int beg, int end) {
    if(beg == end) {
        tree[node] = A[beg];
        return;
    }
    int mid = (beg+end) >> 1;
    build_tree(2*node, beg, mid);
    build_tree(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void point_update(int node, int beg, int end, int ind, int val) {
    if(beg == end) {
        A[ind] += val;
        tree[node] += val;
    }
    int mid = (beg+end) >> 1;
    if(beg <= ind and ind <= mid)                   // ind is in the left child
        point_update(2*node, beg, mid, ind, val);
    else
        point_update(2*node+1, mid+1, end, ind, val);     // ind is in the right child
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int beg, int end, int l, int r) {
    if(r < beg or end < l)      // not in the range
        return 0;
    if(l <= beg and end <= r)   // completely overlaps with [beg, end]
        return tree[node];
    int mid = (beg+end) >> 1;
    int p1 = query(2*node, beg, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1+p2);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, n, x;
    cout << "Enter the array lenght:";
    cin >> n;
    for(i = 1 ; i <= n ; i++)
        cin >> A[i];
    build_tree(1, 1, n);
    point_update(1, 1, n, 5, 6);                // Update A[5] -> A[5]+6
    cout << query(1, 1, n, 2, 7) << endl;       // Sum of [2, 7] range
}