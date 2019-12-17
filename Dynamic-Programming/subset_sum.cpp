// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

#include<bits/stdc++.h>
using namespace std;

int n, ar[105], dp[100005][105];

bool solve(int sum)
{
	memset(dp, false, sizeof(dp));
	int c_sum, c_ind;

	for(c_ind = 0 ; c_ind < n ; c_ind++)
		dp[0][c_ind] = true;
	for(c_sum = 1 ; c_sum <= sum ; c_sum++)
	{
		for(c_ind = 0 ; c_ind < n ; c_ind++)
		{
			if(c_sum >= ar[c_ind]) // check if current element >= current element
				dp[c_sum][c_ind] = dp[c_sum - ar[c_ind]][c_ind - 1] or dp[c_sum][c_ind - 1]; // either consider the element or leave out the element
			else
				dp[c_sum][c_ind] = dp[c_sum][c_ind - 1]; // not consider the element
		}
	}
	return dp[sum][n-1];
}


int main()
{
	int t, i, sum;

	cin>>t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp)); // reset dp table
		sum = 0;

		cin>>n;
		for(i = 0 ; i < n ; i++)
		{
			cin>>ar[i];
			sum += ar[i];
		}

		if(sum % 2 == 1) // if total sum is odd, partition is not possible
		{
			printf("NO\n");
			continue;
		}
		else
			sum /= 2;

		if(solve(sum))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
