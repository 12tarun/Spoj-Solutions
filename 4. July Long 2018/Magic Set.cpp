#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		ll ans = 0;
		cin>>n>>m;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int c = 0;
		for(int i=0;i<n;i++)
		{
			if(a[i]%m==0)
			{
				c++;
			}
		}
		ans = (ll)pow(2,c) - 1;
		cout<<ans<<"\n";
	}
	return 0;
}
