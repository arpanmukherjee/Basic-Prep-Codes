/*
https://practice.geeksforgeeks.org/problems/edit-distance/0
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;

void solve()
{
    int dp[n+5][m+5];
    int i, j;
    for(i = 0 ; i <= n ; i++)
        dp[i][0] = i;
    for(j = 0 ; j <= m ; j++)
        dp[0][j] = j;
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= m ; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            if(s1[i-1] == s2[j-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    cout << dp[n][m] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin >> s1 >> s2;
        solve();
    }
    return 0;
}