// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, i, j, ans;
	int ar[305], lis[305];

	cin>>t;

	while(t--)
	{
		cin>>n;
		for(i = 0 ; i < n ; i++)
		{
			cin>>ar[i];
			lis[i] = 1;
		}

		ans = 0;
		for(i = 0 ; i < n ; i++)
		{
			for(j = 0 ; j < i ; j++)
			{
				if(ar[i] > ar[j])
					lis[i] = max(lis[i], 1+lis[j]);
			}
			ans = max(ans, lis[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
