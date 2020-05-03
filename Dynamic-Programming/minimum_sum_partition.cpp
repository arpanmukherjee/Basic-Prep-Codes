// https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

#include<bits/stdc++.h>
using namespace std;

int n, dp[1000][55];
vector<int> a;

int get_sum(int sum, int ind)
{
    if(sum == 0)
        return dp[sum][ind] = 1;
    if(sum < 0 or ind < 0)
        return 0;
    if(dp[sum][ind] != -1)
        return dp[sum][ind];
    dp[sum][ind] = get_sum(sum-a[ind], ind-1) or get_sum(sum, ind-1);
    return dp[sum][ind];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    int i, total, target1, target2, ans;
    bool flag1, flag2;
    total = 0;
    for(i = 0 ; i < n ; i++)
        total += a[i];
    target1 = total/2;
    target2 = target1 + 1;
    ans = INT_MAX;
    while ((target1 >= 1 or target2 <= total) and ans != INT_MAX)
    {
        flag1 = get_sum(target1, n - 1);
        flag2 = get_sum(target2, n - 1);
        if(flag1)
            ans = min(ans, abs(total-target1));
        if(flag2)
            ans = min(ans, abs(total-target2));
        target1--;
        target2++;
    }
    cout << ans << endl;
}

int main()
{
    int t, i, elem;
    cin >> t;
    while (t--)
    {
        a.clear();
        cin >> n;
        for(i = 0 ; i < n ; i++)
        {
            cin >> elem;
            a.push_back(elem);
        }
        solve();
    }
    return 0;
}