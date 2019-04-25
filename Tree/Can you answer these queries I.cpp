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
ll a[50010];
struct seg
{
	ll maxsum;ll prfsum;ll sufsum;ll totsum;
};
seg tree[200200];

seg query(ll x,ll y,ll node,ll s,ll e)
{
	seg T;
	if(s>e || x>e || s>y)
	{
		T.prfsum=T.sufsum=T.maxsum=INT_MIN;T.totsum=0;return T;
	}
	if(x<=s && e<=y) return tree[node];
	ll mid=(s+e)/2;
	seg l=query(x,y,2*node,s,mid);
	seg r=query(x,y,2*node+1,mid+1,e);
	T.maxsum = max(max(l.maxsum,r.maxsum),l.sufsum+r.prfsum);
	T.prfsum = max(l.prfsum,l.totsum+r.prfsum);
	T.sufsum = max(r.sufsum,r.totsum+l.sufsum);
	T.totsum = l.totsum+r.totsum;
	return T;
}

void build(ll node,ll s,ll e)
{
	if(s==e)
	{
		tree[node].totsum=a[s];
		tree[node].maxsum=a[s];
		tree[node].prfsum=a[s];
		tree[node].sufsum=a[s];
		return;
	}	
	ll mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	tree[node].maxsum = max(max(tree[2*node].maxsum,tree[2*node+1].maxsum),tree[2*node].sufsum+tree[2*node+1].prfsum);
	tree[node].prfsum = max(tree[2*node].prfsum,tree[2*node].totsum+tree[2*node+1].prfsum);
	tree[node].sufsum = max(tree[2*node+1].sufsum,tree[2*node+1].totsum+tree[2*node].sufsum);
	tree[node].totsum = tree[2*node].totsum+tree[2*node+1].totsum;
}
 
int main()
{
	fastIO
	ll n;cin>>n;rep(i,1,n,1)cin>>a[i];
	build(1,1,n);
	ll m;cin>>m;
	while(m--)
	{
		ll x,y;cin>>x>>y;
		seg ans=query(x,y,1,1,n);
		cout<<ans.maxsum<<"\n";
	}
	return 0;
}
