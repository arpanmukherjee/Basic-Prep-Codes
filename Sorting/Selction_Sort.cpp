#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
				swap(a[j],a[i]);
		}
	}
}

int main()
{
	int n,i,j,temp;
	printf("Enter the array size:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the sorted array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	selection_sort(a,n);
	printf("Sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
