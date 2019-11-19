#include<bits/stdc++.h>
using namespace std;


void merge(int a[],int low,int mid,int high)
{
	int i,j,k;
	int b[1000];
	k=low;
	i=low;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i]>a[j])
		{
			b[k]=a[j];
			j++;
		}
		else
		{
			b[k]=a[i];
			i++;
		}
		k++;
	}
	if(i>mid)
	{
		for(i=j;i<=high;i++)
		{
			b[k]=a[i];
			k++;
		}
	}
	else if(j>high)
	{
		for(j=i;j<=mid;j++)
		{
			b[k]=a[j];
			k++;
		}
	}
	for(i=low;i<=high;i++)
		a[i]=b[i];
}

void merge_sort(int a[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,h);
		merge(a,l,m,h);
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
	merge_sort(a,0,n-1);
	printf("Sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
