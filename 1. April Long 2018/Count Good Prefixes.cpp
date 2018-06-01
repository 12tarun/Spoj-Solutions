#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ca = 0; ll cb = 0;

ll calculate(string s)
{
	ll i;ll count = 0;
	for(i=0;i<s.size();i++)
	{
		if(s[i] == 'a')
		{
			ca++;
		}
		else if(s[i] == 'b')
		{
			cb++;
		}			
		if(ca>cb)
		{
			count++;
		}
	}
	if(ca == cb)
	{
		count = count + s.size() + 1;
	}
	return count;
}
 
int main()
{
	ll t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		ca = 0; cb = 0;
		string s; ll n;
		cin>>s;
		cin>>n;
		ll i;
		ll cal; ll ans; ll h = 0;	
		for(i=1;i<=n;i++)
		{
			cal = calculate(s);
			h = h + cal;
			if(cal == s.size())
			{
				ans = (n-i)*s.size() + h;
				break;
			}
			else if(cal == 0)
			{
				ans = h;
				break;
			}
			else if(cal > s.size())
			{
				ans = n*(cal-s.size()-1);
				break;
			}
			else if(cal < s.size() && (i==n))
			{
				ans = h;
	    	}                          
		}
		cout<<ans<<"\n";
	}
	return 0;
}
 
