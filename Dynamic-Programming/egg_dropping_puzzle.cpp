// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n_floor, n_egg, val, c_floor;
	int dp[55][15];
	memset(dp, 0, sizeof(dp));
	for(n_egg=1; n_egg<15; n_egg++)
	{
		for(n_floor=1; n_floor<55; n_floor++)
		{
			if(n_egg==1) //base case
			{
				dp[n_floor][n_egg] = n_floor;
				continue;
			}

			val = 100000000;
			for(c_floor=1 ; c_floor<=n_floor; c_floor++) //current floor
				val = min(val, 1 + max(dp[c_floor-1][n_egg-1], dp[n_floor-c_floor][n_egg]));
			dp[n_floor][n_egg] = val;
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>n_egg>>n_floor;
		cout<<dp[n_floor][n_egg]<<endl;
	}
	return 0;
}
