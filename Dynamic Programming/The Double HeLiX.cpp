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
ll a[10004],b[10004],pra[10004]={0},prb[10004]={0};
 
ll bs(ll n, ll nd)
{
	ll st=0; ll mid;
	while(st<=nd)
	{
		mid=(st+nd)/2;
		if(b[mid]==n) return mid;
		else if(b[mid]<n) st=mid+1;
		else nd=mid-1;
	}
	return -1;
}
 
int main() 
{
	fastIO
	while(true)
	{
		ll n1,n2;cin>>n1;if(n1==0)return 0;vector<ll> ind1,ind2; ll ans=0;
		for(ll i=0;i<n1;i++)cin>>a[i];cin>>n2;for(ll i=0;i<n2;i++)cin>>b[i];
		for(ll i=0;i<n1;i++)
		{
			ll x=bs(a[i],n2-1);
			if(x!=(-1))
			{
				ind1.pb(i);ind2.pb(x);
			}
		}
		pra[0]=a[0],prb[0]=b[0];
		for(ll i=1;i<n1;i++) pra[i]=pra[i-1]+a[i];
		for(ll i=1;i<n2;i++) prb[i]=prb[i-1]+b[i];
		if(ind1.size()==0)
		{
			ans=max(pra[n1-1],prb[n2-1]);
		}
		else
		{
			vector<ll> mxsm1,mxsm2;
			mxsm1.pb(pra[ind1[0]]),mxsm2.pb(prb[ind2[0]]);
			for(ll i=1;i<ind1.size();i++)
			{
				mxsm1.pb(pra[ind1[i]]-pra[ind1[i-1]]);
				mxsm2.pb(prb[ind2[i]]-prb[ind2[i-1]]);
			}
			mxsm1.pb(pra[n1-1]-pra[ind1[ind1.size()-1]]);
			mxsm2.pb(prb[n2-1]-prb[ind2[ind2.size()-1]]);
			for(ll i=0;i<mxsm1.size();i++) ans+=max(mxsm1[i],mxsm2[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
