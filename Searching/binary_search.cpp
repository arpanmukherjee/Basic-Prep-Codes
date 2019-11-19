#include<bits/stdc++.h>
using namespace std;
int binary_search(int a[],int n,int x)
{
	int l,h,m;
	l=0;
	h=n-1;
	while(l<=h)
	{
		m=(l+h)/2;
		if(a[m]==x)
			return m+1;
		else if(a[m]>x)
			h=m-1;
		else
			l=m+1;
	}
	return -1;
}

int main()
{
	int n,i,res,x;
	printf("Enter the array size:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the sorted array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n); //cpp stl sort fucntion to sort the array
	printf("Enter the number you want to search:");
	scanf("%d",&x);
	res=binary_search(a,n,x);
	if(res==-1)
		printf("Sorry element not found!\n");
	else
		printf("Element found at position:%d\n",res);
	return 0;
}
