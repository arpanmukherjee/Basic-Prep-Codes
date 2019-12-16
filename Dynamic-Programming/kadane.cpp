// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, max_sum, temp_sum, i, num;
	bool all_neg;
	vector<int> ar;
	cin>>t;
	while (t--)
	{
		all_neg = true;
		ar.clear();
		cin>>n;
		for(i=0; i<n; i++)
		{
			cin>>num;
			if(num >= 0)
				all_neg = false;
			ar.push_back(num);
		}

		temp_sum = max_sum = 0;
		if(all_neg)
			max_sum = ar[0];

		for(i=0; i<n; i++)
		{
			temp_sum += ar[i];
			max_sum = max(max_sum, temp_sum);
			if(temp_sum < 0)
				temp_sum = 0;
			if(all_neg)
				max_sum = max(max_sum, ar[i]);
		}
		cout<<max_sum<<endl;
	}
	return 0;
}
