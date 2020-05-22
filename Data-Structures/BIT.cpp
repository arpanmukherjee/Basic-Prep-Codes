// Implementation of Fenwick Tree(Binary Indexed Tree)
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
int tree[N];    // Fenwick tree takes O(N) memory
int n;          // No of elements

void point_update(int ind, int val) {   // Update A[ind] = A[ind] + val
    while(ind <= n) {
        tree[ind] += val;
        ind += (ind & -ind);
    }
}

int range_query(int ind) {  // Sum of [1, ind]
    int ans = 0;
    while(ind > 0) {
        ans += tree[ind];
        ind -= (ind & -ind);
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(tree, 0, sizeof(tree));
    int i, n, x;
    cout << "Enter the array lenght:";
    cin >> n;
    for(i = 1 ; i <= n ; i++) {
        cin >> A[i];
        point_update(i, A[i]);
    }
    cout << "Sum of the range [3, 14]: " << (range_query(14) - range_query(2)) << endl;
}