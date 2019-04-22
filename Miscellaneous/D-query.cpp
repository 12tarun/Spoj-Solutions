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
ll freq[1000010]={0};map<pl,ll> m;

bool cmp(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
	return a.second < b.second;
}

int main()
{
	fastIO
	ll n;cin>>n;ll a[n+1];for(ll i=1;i<=n;i++) cin>>a[i];
	ll q;cin>>q;vector<pl> quer;vector<pl> unsortq;ll rn=sqrt(n);
	for(ll i=1;i<=q;i++)
	{
		ll a,b;cin>>a>>b;quer.pb(mp(a,b));unsortq.pb(mp(a,b));
	} 
	sort(quer.begin(),quer.end());ll j=0,k=0;
	for(ll i=1;i<=(rn+1);i++)
	{
		ll e=(i*rn);
		while(j<q && quer[j].fi<=e)
		{
			j+=1;
		}
		sort(quer.begin()+k,quer.begin()+j,cmp);
		k=j;
	}
	ll ans=0;ll st=0,nd=0;
	st=quer[0].fi;nd=quer[0].se;
	for(ll i=st;i<=nd;i++)
	{
		freq[a[i]]+=1;
		if(freq[a[i]]==1)ans+=1;
		m[quer[0]]=ans;
	}
	for(ll i=1;i<q;i++)
	{
		ll st2=quer[i].fi;ll nd2=quer[i].se;
		if(nd2>nd)
		{
			nd+=1;
			while(nd2!=nd)
			{
				freq[a[nd]]+=1;
				if(freq[a[nd]]==1) ans+=1;
				nd+=1;
			}
			freq[a[nd]]+=1;
			if(freq[a[nd]]==1) ans+=1;
		}
		else if(nd2<nd)
		{
			while(nd2!=nd)
			{
				freq[a[nd]]-=1;
				if(freq[a[nd]]==0) ans-=1;
				nd-=1;
			}
		}
		if(st2>st)
		{
			while(st2!=st)
			{
				freq[a[st]]-=1;
				if(freq[a[st]]==0) ans-=1;
				st+=1;
			}
		}
		else if(st2<st)
		{
			st-=1;
			while(st2!=st)
			{
				freq[a[st]]+=1;
				if(freq[a[st]]==1) ans+=1;
				st-=1;
			}
			freq[a[st]]+=1;
			if(freq[a[st]]==1) ans+=1;
		} 
		m[quer[i]]=ans;
	} 
	for(ll i=0;i<q;i++)
	{
		cout<<m[unsortq[i]]<<"\n";
	}
	return 0;
}
