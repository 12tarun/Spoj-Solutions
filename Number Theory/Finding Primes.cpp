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
#define repe(i,xi,yi,zi) for(ll i=xi;i<=yi;i+=zi)
#define rrep(i,xi,yi,zi) for(ll i=xi;i>=yi;i-=zi)
#define pq priority_queue<long long>
#define rpq priority_queue<long long, vector<long long>, greater<long long> >
#define umap tr1::unordered_map
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
ll sv[10000010];
 
int main()
{
	fastIO
	sv[0]=sv[1]=-1;sv[2]=1;rep(i,4,10000010,2) sv[i]=-1;ll cnt=2;  
	rep(i,3,10000010,2)
	{
		if(sv[i]!=(-1))
		{
			sv[i]=cnt;cnt+=1;rep(j,i*i,10000010,2*i) sv[j]=-1;
		} 
	}
	ll t;cin>>t;
	while(t--)
	{
		ll n;cin>>n;ll temp=n;ll h=n/2;
		while(sv[temp]==-1) temp-=1;
		while(sv[h]==-1 && h>0) h-=1;
		if(h) cout<<sv[temp]-sv[h]<<"\n";
		else cout<<sv[temp]<<"\n";
	}
	return 0;
} 
