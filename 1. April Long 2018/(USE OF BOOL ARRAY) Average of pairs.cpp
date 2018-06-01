#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t,i,j,k,l,n,m,c;
	cin>>t;
	bool f[2*1003];
	while(t--)
	{  
		cin>>n;
		c=0;
		memset(f,false,sizeof(f));
		ll a[n];
		for(i=0;i<n;i++)
		{
		cin>>a[i];
		f[2*a[i]]=true;
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			if(f[a[i]+a[j]]==true)
			c++;
		}
		cout<<c<<endl;
	}
}
