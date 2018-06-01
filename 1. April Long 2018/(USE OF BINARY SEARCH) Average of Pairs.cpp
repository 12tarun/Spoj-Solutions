#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
 
int search(int sum, int min, int max)
{
	int f = 0;
	int mid;
	while(min<=max)
	{
		mid = (min+max)/2;
		if(sum == b[mid])
		{
			f = 1;
			break;
		}
		else if(sum > b[mid])
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}
	return f;
}
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i; int j; int even = 0; int odd = 0; int k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[i] = 2*a[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		int count = 0;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				int sum = a[i] + a[j];
				if(sum%2 == 0)
				{
					if(sum<=b[n-1])
					{
						k = search(sum,i,j);
						if(k == 1)
						{
							count++;
						}
					}
				}
			}
		}
		cout<<count<<"\n";
	}
	return 0;
} 
