#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b; ll counta = 0; int countc = 0;
		cin>>a>>b;
		if(a == b)
		{
			cout<<"0\n";
		}
		else if((b == 0 || b == 1) && a!=0)
		{
			cout<<"-1\n";
		}
		else
		{
			while(a>0)
			{
				a = a & a-1;
				counta++;	
			}
			ll c = b-1;
			while(c>0)
			{
				c = c & c-1;
				countc++;	
			}
			if(counta>countc)
			{
				cout<<"2\n";
			}
			else
			{
				ll ans = abs(countc-counta) + 1;
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
