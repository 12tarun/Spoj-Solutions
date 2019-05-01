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
ll a[100100];struct seg{ll m1;ll m2;};seg tree[400400];

void build(ll node,ll s,ll e)
{
	if(s==e)
	{
		tree[node].m1=a[s];tree[node].m2=-1;return;
	}
	ll mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	ll max1=max(tree[2*node].m1,tree[2*node+1].m1);
	ll minim=min(tree[2*node].m1,tree[2*node+1].m1);
	ll max2=max(minim,max(tree[2*node].m2,tree[2*node+1].m2));
	tree[node].m1=max1;tree[node].m2=max2;
}

void update(ll pos,ll val,ll node,ll s,ll e)
{
	if(s==e)
	{
		tree[node].m1=val;return;
	}
	ll mid=(s+e)/2;
	if(pos<=mid) update(pos,val,2*node,s,mid);
	else update(pos,val,2*node+1,mid+1,e);
	ll max1=max(tree[2*node].m1,tree[2*node+1].m1);
	ll minim=min(tree[2*node].m1,tree[2*node+1].m1);
	ll max2=max(minim,max(tree[2*node].m2,tree[2*node+1].m2));
	tree[node].m1=max1;tree[node].m2=max2;
}

seg query(ll l,ll r,ll node,ll s,ll e)
{
	if(l<=s && e<=r) return tree[node];
	seg T;
	if(e<l || r<s)
	{
		T.m1=T.m2=-1;return T;
	}
	ll mid=(s+e)/2;
	seg lft=query(l,r,2*node,s,mid);
	seg rht=query(l,r,2*node+1,mid+1,e);
	ll max1=max(lft.m1,rht.m1);
	ll minim=min(lft.m1,rht.m1);
	ll max2=max(minim,max(lft.m2,rht.m2));
	T.m1=max1;T.m2=max2;
	return T;
}

int main()
{
	fastIO
	ll n;cin>>n;rep(i,1,n,1)cin>>a[i];ll q;cin>>q;build(1,1,n);
	while(q--)
	{
		char x;ll y,z;cin>>x>>y>>z;
		if(x=='U')
		{
			update(y,z,1,1,n);
		}
		else
		{
			seg ans=query(y,z,1,1,n);
			cout<<ans.m1+ans.m2<<"\n";
		}
	}
	return 0;
}
