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
vector<vector<pl> > G(10010);ll n,m,k,s,t;ll d1[10010],d2[10010],d3[10010];

void dijikstra(ll node)
{
	set<pl> dist;d3[node]=0;dist.insert(mp(0,node));
	while(!dist.empty())
	{
		ll x=(*dist.begin()).fi;ll y=(*dist.begin()).se;
		dist.erase(dist.begin());
		for(ll i=0;i<G[y].size();i++)
		{
			if(d3[G[y][i].fi] > (x+G[y][i].se))
			{
				if(dist.find(mp(d3[G[y][i].fi],G[y][i].fi))!=dist.end())
				{
					dist.erase(mp(d3[G[y][i].fi],G[y][i].fi));
				}
				d3[G[y][i].fi] = x+G[y][i].se;
				dist.insert(mp(d3[G[y][i].fi],G[y][i].fi));
			}
		}
	}
}

int main()
{
	fastIO
	ll tests;cin>>tests;
	while(tests--)
	{
		cin>>n>>m>>k>>s>>t;
		ll infi = 300000000;ll arr[m+2][3];
		for(ll i=0;i<10010;i++) 
		{
			G[i].clear();d3[i]=infi;
		}
		for(ll i=1;i<=m;i++)
		{
			ll di,ci,qi;
			cin>>di>>ci>>qi;
			G[di].pb(mp(ci,qi));
			arr[i][0]=di;arr[i][1]=ci;arr[i][2]=qi;
		}
		dijikstra(s);
		for(ll i=0;i<10010;i++) d1[i]=d3[i];
		for(ll i=0;i<10010;i++) 
		{
			G[i].clear();d3[i]=infi;
		}
		for(ll i=1;i<=m;i++)
		{
			G[arr[i][1]].pb(mp(arr[i][0],arr[i][2]));
		}
		dijikstra(t);
		for(ll i=0;i<10010;i++) d2[i]=d3[i];
		ll minim=d1[t];
		for(ll i=1;i<=k;i++)
		{
			ll p,q,r;cin>>p>>q>>r;
			ll dist1 = d1[p]+d2[q]+r;
			ll dist2 = d1[q]+d2[p]+r;
			ll distmin = min(dist1,dist2);
			if(distmin<minim) minim = distmin;
		}
		if(minim==300000000) cout<<"-1\n";
		else cout<<minim<<"\n";
	}
	return 0;
}
