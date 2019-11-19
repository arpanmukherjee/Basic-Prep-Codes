#include<bits/stdc++.h>
using namespace std;

void quicksort(int a[],int l,in h)
{
	int i,j,pivot,m;
	m=(l+h)/2;
	pivot=a[m];
	i=l
	j=h;
	while(i<=j)
	{
		while(a[i]<pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(i<h)
		quicksort(a,l,m-1);
	if(j>l)
		quicksort(a,m+1,h);
}

int main()
{
	int i,n;
	printf("Enter the array size:");
	scanf("%d",&n);
	int a[n];
	puts("Enter the elements:")
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	puts("Elements after sorting:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
