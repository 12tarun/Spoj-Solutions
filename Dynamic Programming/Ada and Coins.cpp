#include<bits/stdc++.h>
#define ll long long
#define mod 100000007
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
ll a[100005],psm[100005]={0};bitset<100005> bssum;
 
void subsum(ll i,ll n,ll sum)
{
	bssum[0]=1;
	for(ll i=0;i<n;i++) bssum|=(bssum<<a[i]);
} 
 
int main()
{
	fastIO 
	ll n,q;cin>>n>>q;for(ll i=0;i<n;i++)cin>>a[i];bssum.reset();subsum(0,n,0);psm[0]=1;
	for(ll i=1;i<100005;i++) psm[i]=psm[i-1]+bssum[i];
	for(ll i=0;i<q;i++)
	{
		ll s,e;cin>>s>>e;
		ll ans=psm[e]-psm[s-1];
		cout<<ans<<"\n";
	}
	return 0;
}  
