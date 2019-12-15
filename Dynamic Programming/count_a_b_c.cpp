/*
https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0
*/

#include <bits/stdc++.h>
using namespace std;

long long get_nCr(int n, int r)
{
	if(r==0)
		return 1LL;
	else if(r==1)
		return n;
	return (n*(n-1))/2;
}

int main()
{
	int t, n, c_b, c_c;
	long ans;
	cin>>t;
	while (t--)
	{
		ans = 0;
		cin>>n;
		for(c_b = 0; c_b <= 1; c_b++) //count of b
		{
			for(c_c = 0; c_c <= 2; c_c++) //count of c
			{
				ans += (get_nCr(n, c_b)*get_nCr(n-c_b, c_c));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
