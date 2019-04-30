#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int,int>
#define pl pair<long long,long long>
#define fi first
#define se second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
ll dp[102][100001];
 
ll winner(ll i,ll m,ll n,ll nc)
{
	if(i==(m+1) || m==0)
	{
		if(n>nc) return 1;
		else return 0;
	}
	if(dp[i][n]==(-1))
	{
		ll u=n;
		ll w=n%10;n=n/10;
		ll x=n%10;n=n/10;
		ll y=n%10;n=n/10;
		ll z=n%10;n=n/10;
		n=u;
		ll a,b,c,d;
		if(w!=9) a=n+1;
		else a=(n/10)*10;
		if(x!=9) b=n+10;
		else
		{
			ll temp=n%10;
			b=((n/100)*100)+temp;
		}
		if(y!=9) c=n+100;
		else
		{
			ll temp=n%100;
			c=((n/1000)*1000)+temp;
		}
		if(z!=9) d=n+1000;
		else
		{
			ll temp=n%1000;
			d=temp;
		}
		if((i%2)!=0)
		{	
			dp[i][n]=winner(i+1,m,a,nc)|winner(i+1,m,b,nc)|winner(i+1,m,c,nc)|winner(i+1,m,d,nc); // Ada's chance so any 1 winning possibility will result in her win.
		}
		else
		{
			dp[i][n]=winner(i+1,m,a,nc)&winner(i+1,m,b,nc)&winner(i+1,m,c,nc)&winner(i+1,m,d,nc); // Vinit's chance so only all winning possibility of Ada will result in Ada's win.
		}
	}
	return dp[i][n];
}
 
int main()
{
	fastIO
	ll t;cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		ll n,m;cin>>n;cin>>m;
		ll ans=winner(1,m,n,n);
		if(ans==1) cout<<"Ada\n";
		else cout<<"Vinit\n";
	}
	return 0;
}
