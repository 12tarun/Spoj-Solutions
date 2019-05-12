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
 
int main()
{
	fastIO
	while(1)
	{
		ll n;cin>>n;if(n==0)break;ll ans=0;
		vl l(n);rep(i,0,n,1)cin>>l[i];sort(l.begin(),l.end());
		rep(i,0,n-1,1)
		{
			rep(j,i+1,n,1)
			{
				ll temp=upper_bound(l.begin(),l.end(),l[i]+l[j])-l.begin();
				ans+=(n-temp);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
