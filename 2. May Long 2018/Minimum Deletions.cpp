#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n; int j;
		cin>>n;
		int a[n]; int i;
		int count;
		int c = 0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a, a+n);
		for(i=2;i<=a[n-1];i++)
		{
			count = 0;
			for(j=0;j<n;j++)
			{
				if(a[j]%i != 0)
				{
					break;
				}
				else
				{
					count++;
				}				
			}
			if(count == n)
			{
				c = 1;
				cout<<"-1\n";
				break;
			}
		}
		if(c == 0)
		{
			cout<<"0\n";
		}
	}
	return 0;
}
