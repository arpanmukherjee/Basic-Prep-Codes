// https://practice.geeksforgeeks.org/problems/form-a-palindrome/0

#include<bits/stdc++.h>
using namespace std;

string s;
int dp[45][45];

int solve(int beg, int end)
{
	if(dp[beg][end] == -1)
	{
		int ans;
		if(beg >= end)
			ans = 0;
		else if(s[beg] == s[end])
			ans = solve(beg+1, end-1);
		else
			ans = 1 + min(solve(beg+1, end), solve(beg, end-1));
		dp[beg][end] = ans;
	}
	return dp[beg][end];
}

int main()
{
	int t, beg, end;
	cin>>t;
	while (t--)
	{
		cin>>s;
		memset(dp, -1, sizeof(dp));
		beg = 0;
		end = s.length() - 1;
		cout<<solve(beg, end)<<endl;
	}
	return 0;
}
