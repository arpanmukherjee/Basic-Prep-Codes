#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

int main()
{
	int n,i,j,temp;
	printf("Enter the array size:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	insertion_sort(a,n);
	printf("Sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
