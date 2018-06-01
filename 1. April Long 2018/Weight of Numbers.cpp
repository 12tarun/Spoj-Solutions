#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, w;
		cin>>n>>w;
		ll x; ll i;
		if(w>8 || w<(-9))
		{
			cout<<"0\n";
		}
		else if(w == 8)
		{
			x = 1;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == 7)
		{
			x = 2;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == 6)
		{
			x = 3;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == 5)
		{
			x = 4;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == 4)
		{
			x = 5;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == 3)
		{
			x = 6;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == 2)
		{
			x = 7;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == 1)
		{
			x = 8;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-9))
		{
			x = 1;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-8))
		{
			x = 2;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-7))
		{
			x = 3;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-6))
		{
			x = 4;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-5))
		{
			x = 5;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-4))
		{
			x = 6;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-3))
		{
			x = 7;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-2))
		{
			x = 8;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (-1))
		{
			x = 9;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
		else if(w == (0))
		{
			x = 9;
			i = 1;
			while(i+8<=n-2)
			{
				x = (x*100000000)%1000000007;
				i=i+8;
			}
			while(i<=n-2)
			{
				x = (x*10)%1000000007;
				i++;
			}
			cout<<x<<"\n";
		}
	}
	return 0;
} 
