// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, ind1, ind2, len1, len2, dp[105][105];
	string str1, str2;
	cin>>t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		cin>>len1>>len2; // length of the string 1 and 2
		cin>>str1>>str2;

		for(ind1 = 1 ; ind1 <= len1 ; ind1++)
		{
			for(ind2 = 1 ; ind2 <= len2 ; ind2++)
			{
				if(str1[ind1-1] == str2[ind2-1])
					dp[ind1][ind2] = max(1 + dp[ind1-1][ind2-1], max(dp[ind1-1][ind2], dp[ind1][ind2-1]));
				else
					dp[ind1][ind2] = max(dp[ind1-1][ind2-1], max(dp[ind1-1][ind2], dp[ind1][ind2-1]));
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
	return 0;
}
