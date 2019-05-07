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
#define rep(i,xi,yi,zi) for(ll i=xi;i<yi;i+=zi)
#define rrep(i,xi,yi,zi) for(ll i=xi;i>=yi;i-=zi)
#define pq priority_queue<long long>
#define rpq priority_queue<long long, vector<long long>, greater<long long> >
#define umap tr1::unordered_map
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
vector<vl> G(1010);ll indig[1010],dp[1010],visited[1010];stack<ll> s;

void topo(ll node)
{
	visited[node]=1;
	rep(i,0,G[node].size(),1)
	{
		if(!visited[G[node][i]])topo(G[node][i]);
	}
	s.push(node);
} 
 
int main()
{
	fastIO
	ll t;cin>>t;
	rep(k,1,t+1,1)
	{
		ll n,r;cin>>n>>r;vl v;vector<pl> ans;
		rep(i,0,1010,1)
		{
			G[i].clear();indig[i]=0;dp[i]=0;visited[i]=0;
		}
		while(r--)
		{
			ll a,b;cin>>a>>b;
			G[b].pb(a);indig[a]+=1;
		}
		rep(i,0,n,1)
		{
			if(!indig[i])
			{
				topo(i);
				dp[i]=1;
			} 
		}
		while(!s.empty())
		{
			v.pb(s.top());s.pop();
		}
		rep(i,0,v.size(),1)
		{
			rep(j,0,G[v[i]].size(),1)
			{
				ll x=G[v[i]][j];
				dp[x]=max(dp[x],dp[v[i]]+1);
			}
		}
		rep(i,0,n,1) ans.pb(mp(dp[i],i));sort(ans.begin(),ans.end());
		cout<<"Scenario #"<<k<<":\n";
		rep(i,0,n,1)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
	}
	return 0;
} 
