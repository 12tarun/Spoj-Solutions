#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m, n;
		cin>>m>>n;
		int a[m], b[m];
		int i, j;
		ll s1 = 0;
		ll s2 = 0;
		ll sum1 = 0;
		ll sum2 = 0;
		for(i=0;i<m;i++)
		{
			cin>>a[i];
			s1 = (s1 + a[i])%mod;
		}
		for(i=1;i<=m;i++)
		{
			sum1 += s1 % mod;
		}		
		for(i=0;i<m;i++)
		{
			cin>>b[i];
			s2 = (s2 + b[i])%mod;
		}
		for(i=1;i<=m;i++)
		{
			sum2 += s2 % mod;
		}
		if(n == 1)
		{
			cout<<sum1<<"\n";
		}
		else if(n == 2)
		{
			cout<<sum2<<"\n";
		}
		else
		{
			ll c[n];
			c[0] = sum1;
			c[1] = sum2;
		//	cout<<c[0]<<" "<<c[1]<<" ";
			for(i=2;i<n;i++)
			{
				c[i] = (c[i-1] + c[i-2])%mod;
			}
			cout<<c[i-1]<<"\n";
		}
	}
	return 0;
}
