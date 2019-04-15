#include<bits/stdc++.h>
#include<tr1/unordered_map>
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
#define umap tr1::unordered_map
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std; 
ll a[100010];vector<ll> ans;

void bs(ll s,ll e,ll n,ll c)
{
	ll mid;
	while(s<=e)
	{
		mid=(s+e)/2;
		ll prev=0;ll j=0;ll k=0;
		ll temp=c-1;
		while(temp>0)
		{
			while(a[j]-a[prev] < mid)
			{
				j+=1;
				if(j>=n)
				{
					k=1;break;
				}
			}
			if(k==1) break;
			prev=j;
			temp-=1;
		}
		if(temp==0)
		{
			ans.pb(mid);
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
}

int main()
{
	fastIO
	ll tests;cin>>tests;
	while(tests--)
	{
		ll n,c;cin>>n>>c;
		for(ll i=0;i<n;i++) cin>>a[i];
		ans.clear();
		sort(a,a+n);
		ll minim=0;
		ll maxim=a[n-1]-a[0];
		bs(minim,maxim,n,c);
		cout<<ans[ans.size()-1]<<"\n";
	}
	return 0;
}
