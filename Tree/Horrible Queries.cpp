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
#define rep(i,xi,yi,zi) for(ll i=xi;i<=yi;i+=zi)
#define rrep(i,xi,yi,zi) for(ll i=xi;i>=yi;i-=zi)
#define pq priority_queue<long long>
#define rpq priority_queue<long long, vector<long long>, greater<long long> >
#define umap tr1::unordered_map
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
vector<pl> tree(400400);

void update(ll x,ll y,ll z,ll node,ll s,ll e)
{
	ll mid=(s+e)/2;
	if(tree[node].second!=0)
	{
		tree[node].first+=((e-s+1)*tree[node].second);
		if(s!=e)
		{
			tree[2*node].second+=tree[node].second;
			tree[2*node+1].second+=tree[node].second;
		}
		tree[node].second=0;
	}
	if(x<=s && e<=y)
	{		
		tree[node].first+=((e-s+1)*z);
		if(s!=e)
		{
			tree[2*node].second+=z;
			tree[2*node+1].second+=z;
		}
		return;
	}
	if(x>e || y<s) return;
	update(x,y,z,2*node,s,mid);
	update(x,y,z,2*node+1,mid+1,e);
	tree[node].first=tree[2*node].first+tree[2*node+1].first;
}

ll query(ll x,ll y,ll node,ll s,ll e)
{
	ll mid=(s+e)/2;
	if(tree[node].second!=0)
	{
		tree[node].first+=((e-s+1)*tree[node].second);
		if(s!=e)
		{
			tree[2*node].second+=tree[node].second;
			tree[2*node+1].second+=tree[node].second;
		}
		tree[node].second=0;
	}
	if(x>e || s>y) return 0;
	if(x<=s && e<=y) return tree[node].first;
	ll l=query(x,y,2*node,s,mid);
	ll r=query(x,y,2*node+1,mid+1,e);
	return l+r;
}

int main()
{
	fastIO
	ll t;cin>>t;
	while(t--)
	{
		rep(i,0,400399,1)
		{
			tree[i].first=0;tree[i].second=0;
		}
		ll n,c;cin>>n>>c;
		while(c--)
		{
			ll w,x,y;cin>>w>>x>>y;
			if(!w)
			{
				ll z;cin>>z;
				update(x,y,z,1,1,n);
			}
			else
			{
				cout<<query(x,y,1,1,n)<<"\n";
			}
		}
	}
	return 0;
}
