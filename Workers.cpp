#include<bits/stdc++.h>
using namespace std;
int calculate(string s)
{
	int i;int ca = 0; int cb = 0; int count = 0;
	for(i=0;i<s.size();i++)
	{
		if(s[i] == 'a')
		{
			ca++;
		}
		else
		{
			cb++;
		}			
		if(ca>cb)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		string s; int n;
		cin>>s;
		cin>>n;
		int i;
		string ns = s;
		int j; int ans;		
		for(i=1;i<=n;i++)
		{
			
		}
		if(count == ns.size())
		{
			ans = n*count;
		}
		else if(count == 0)
		{
			ans = 0;
		}
		else if(ca>cb)
		{
			
		}
		else if(cb>ca)
		{
			
		}
		else
		{
			
		}
		cout<<ans;
	}
	return 0;
}

