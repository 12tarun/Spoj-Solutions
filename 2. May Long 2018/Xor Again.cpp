#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll a[n];
		int i; int j;
		int x = 0; ll ans = 0; ll o;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			o = a[i]+a[i];
	//		cout<<o<<" ";
			ans = ans^o;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
