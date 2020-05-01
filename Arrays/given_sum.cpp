/*
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
	int T, N, S, i, j, temp, sum, beg, end;
	bool flag;
	vector<int> A;
	scanf("%d", &T);

	while (T--)
	{
		A.clear();
		sum = 0;
		flag = false;

		scanf("%d %d", &N, &S);
		A.push_back(0);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &temp);
			A.push_back(temp + A[i]);
		}
		i = 0;
		j = 1;
		while (j <= N and i <= N)
		{
			sum = A[j] - A[i];
			if(sum == S)
			{
				flag = true;
				beg = i + 1;
				end = j;
				break;
			}
			else if(sum < S)
				j++;
			else
			{
				while (i < N and A[j] - A[i] > S)
					i++;
			}
		}

		if(flag)
			printf("%d %d\n", beg, end);
		else
			printf("-1\n");
	}
	return 0;
}
