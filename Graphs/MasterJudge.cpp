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
vector<vector<pl> > G(10010);ll depth[10010],parent[10010],lenDepth[10010];ll n;ll memo[10010][60];

// Calculating totol depth from root for each node and finding out immediate parent of each node too (for root immediate parent is -1).
void dfs(ll node)
{
	for(ll i=0;i<G[node].size();i++)
	{
		if(depth[G[node][i].fi]==(-1))
		{
			parent[G[node][i].fi] = node;
			lenDepth[G[node][i].fi] = lenDepth[node]+G[node][i].se;
			depth[G[node][i].fi] = depth[node]+1;
			dfs(G[node][i].fi);
		}
	}
}

// First equalizing depth and then finding lca.
ll lca(ll f,ll s)
{
	
	if(depth[f]<depth[s])
	{
		ll temp=f;
		f=s;
		s=temp;
	}
	ll diff = depth[f]-depth[s];
	for(ll i=0;i<50;i++)
	{
		if((diff>>i)&1) f=memo[f][i];
	}
	
	if(f==s) return f;
	
	for(ll i=49;i>=0;i--)
	{
		if(memo[f][i]!=memo[s][i])
		{
			f = memo[f][i]; s = memo[s][i];
		}
	}
	return memo[f][0];
}

int main()
{
	fastIO
	ll t;cin>>t;
	while(t--)
	{
		cin>>n;
		for(ll i=0;i<10010;i++) G[i].clear();
		memset(depth,-1,sizeof(depth));
		memset(parent,-1,sizeof(parent));
		memset(memo,-1,sizeof(memo));
		memset(lenDepth,-1,sizeof(lenDepth));
		for(ll i=1;i<=n-1;i++)
		{
			ll a,b,c;cin>>a>>b>>c;
			G[a].pb(mp(b,c));G[b].pb(mp(a,c));
		}
		ll root;
		for(ll i=0;i<=n;i++)
		{
			if(G[i].size()>0)
			{
				root=i;break;
			}
		}
		depth[root]=0;parent[root]=-1;lenDepth[root]=0;
		dfs(root);
		for(ll i=0;i<10010;i++)
		{
			if(parent[i]!=(-1)) memo[i][0] = parent[i];	
		}
		for(ll i=0;i<10010;i++)
		{
			for(ll j=1;j<50;j++)
			{
				if(memo[memo[i][j-1]][j-1]!=(-1)) memo[i][j]=memo[memo[i][j-1]][j-1];
			}
		}
		while(true)
		{
			string str;cin>>str;
			if(str=="DONE") break;
			ll f,s;cin>>f>>s;
			ll getLca = lca(f,s);
			if(str=="DIST")
			{
				ll ans = ((lenDepth[f]+lenDepth[s])-(2*lenDepth[getLca]));
				cout<<ans<<"\n";
			}
			else
			{
				ll k;cin>>k;
				ll p=depth[f]-depth[getLca]+1;
				if(p>=k)
				{
					// lift f k-1 times
					for(ll i=0;i<50;i++)
					{
						if(((k-1)>>i)&1) f=memo[f][i];
					}
					cout<<f<<"\n";
				}
				else
				{
					// Lift s lift times
					ll lift = ((depth[f]+depth[s])-(2*depth[getLca])) - k + 1;
					for(ll i=0;i<50;i++)
					{
						if(((lift)>>i)&1) s=memo[s][i];
					}
					cout<<s<<"\n";
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}
