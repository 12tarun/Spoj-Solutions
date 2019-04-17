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
vector<vector<pl> > G(600);ll dist[600];vector<vector<pl> > prnts(600);

// deleting all shortest paths with dfs...
void dfs(ll p,ll c,ll r)
{
	for(ll i=0;i<G[p].size();i++)
	{
		if(G[p][i].fi==c)
		{
			G[p].erase(G[p].begin()+i);break;
		}
	}
	if(p==r || prnts[p].size()==0) return;
	else
	{
		for(ll i=0;i<prnts[p].size();i++)
		{
			dfs(prnts[p][i].fi,p,r);
		}
	} 
}

// calculating shortest path...
void dijkstra(ll st)
{
	set<pl> s;dist[st]=0;s.insert(mp(0,st));
	while(!s.empty())
	{
		ll x=(*s.begin()).fi;ll y=(*s.begin()).se;s.erase(s.begin());
		for(ll i=0;i<G[y].size();i++)
		{
			if(dist[G[y][i].fi] >= (x+G[y][i].se))
			{
				if(s.find(mp(dist[G[y][i].fi],G[y][i].fi))!=s.end())
				{
					s.erase(mp(dist[G[y][i].fi],G[y][i].fi));	
				}
				dist[G[y][i].fi] = x+G[y][i].se;
				s.insert(mp(dist[G[y][i].fi],G[y][i].fi));
				// saving all shortest paths...
				if(prnts[G[y][i].fi].size()>0)
				{
					if(prnts[G[y][i].fi][0].se > dist[G[y][i].fi])
					{
						prnts[G[y][i].fi].clear();
					}
				}
				prnts[G[y][i].fi].pb(mp(y,dist[G[y][i].fi]));
			}
		}
	}
}

int main()
{
	fastIO
	while(true)
	{
		for(ll i=0;i<600;i++)
		{
			G[i].clear();prnts[i].clear();dist[i]=300000000;
		} 
		ll n,m;cin>>n>>m;if(n==0 && m==0) return 0;
		ll s,d;cin>>s>>d;
		for(ll i=1;i<=m;i++)
		{
			ll u,v,p;cin>>u>>v>>p;
			G[u].pb(mp(v,p));
		}
		dijkstra(s);		
		if(dist[d]==300000000)
		{
			cout<<"-1\n";continue;
		}
		for(ll i=0;i<prnts[d].size();i++)
		{
			dfs(prnts[d][i].fi,d,s);
		}
		for(ll i=0;i<600;i++) dist[i]=300000000;
		dijkstra(s);
		if(dist[d]==300000000) cout<<"-1\n";
		else cout<<dist[d]<<"\n";
	}
	return 0;
}
