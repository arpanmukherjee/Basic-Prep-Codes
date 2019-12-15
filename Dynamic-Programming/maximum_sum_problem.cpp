// https://practice.geeksforgeeks.org/problems/maximum-sum-problem/0

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, i;
	int dp[100005];
	for (i = 0; i < 100005; i++)
	{
		if(i <= 4)
		{
			dp[i] = i;
			continue;
		}
		dp[i] = max(dp[i/2]+dp[i/3]+dp[i/4], i);
	}

	cin>>t;
	while (t--)
	{
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}
