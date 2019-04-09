#include<bits/stdc++.h>
#define ll long long
#define mod 100000000
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
ll dp[100005];vector<pl> v;
 
ll bs(ll c,ll s,ll e)
{
	while(s<e)
	{
		ll mid=(s+e)/2;
		if(v[mid].first<v[c].second) s=mid+1;
		else e=mid;
	}
	if(s==e && v[s].first>=v[c].second) return s;
	else return -1;
}
 
int main()
{
	fastIO 
	ll n;
	while(cin>>n)
	{
		if(n==(-1)) return 0; v.clear();
		for(ll i=0;i<n;i++)
		{
			ll s,e;cin>>s>>e;v.pb(mp(s,e));
		}
		sort(v.begin(),v.end());memset(dp,0,sizeof(dp));
		dp[n-1]=1;
		for(ll i=n-2;i>=0;i--)
		{
			dp[i]=(1+dp[i+1])%mod;
			ll x=bs(i,i+1,n-1);
			if(x!=(-1)) dp[i]=(dp[x]%mod+dp[i]%mod)%mod;
		}
		vector<ll> w(8);ll ans=dp[0];
		for(ll i=7;i>=0;i--)
		{
			ll d=ans%10;
			w[i]=d;
			ans/=10;
		}
		for(ll i=0;i<8;i++) cout<<w[i]; cout<<"\n";
	}
	return 0;
} 
