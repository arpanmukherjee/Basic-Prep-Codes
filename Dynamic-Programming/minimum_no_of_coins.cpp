// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0

#include<bits/stdc++.h>
using namespace std;

int dp[1000005], prev_state[1000005];
int denominations[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
int n_coins = 10;

void precompute()
{
	memset(dp, 1000000, sizeof(dp));
	int coin, i;
	dp[0] = 0;

	for(coin = 1 ; coin < 1000005 ; coin++)
	{
		for(i = 0 ; i < n_coins ; i++)
		{
			if(coin >= denominations[i])
			{
				if(dp[coin] > 1 + dp[coin - denominations[i]])
				{
					dp[coin] = 1 + dp[coin - denominations[i]];
					prev_state[coin] = coin - denominations[i]; // storing the previous state to retrieve the answer later
				}
				else
					continue;
			}
			else
				break;
		}
	}
}

int main()
{
	precompute();
	int T, N, i;
	cin>>T;
	vector<int> ans;
	while (T--)
	{
		ans.clear();
		cin>>N;
		while (N != 0)
		{
			ans.push_back(N - prev_state[N]);
			N = prev_state[N];
		}
		reverse(ans.begin(), ans.end());
		for(i = 0 ; i < ans.size() ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
