#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,res,x;
	printf("Enter the array size:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the number you want to search:");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
			break;
	}
	if(i==n)
		printf("Sorry element not found!\n");
	else
		printf("Element found at position:%d\n",i+1);
	return 0;
}
