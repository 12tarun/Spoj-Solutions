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
 
int main()
{
	fastIO
	ll t;cin>>t;
	while(t--)
	{
		ll a,b,c,n;cin>>a>>b>>c>>n;ll w=(a+(b*2)+c)%mod;
		pq pqmax;rpq pqmin;pqmax.push(1);pqmin.push(w);ll z;ll ans;
		if(n==1) ans=1;
		else ans=1+w;
		rep(i,3,n,1)
		{
			if(pqmax.size()>=pqmin.size()) z=pqmax.top();
			else z=pqmin.top(); 
			ll u=((a*z)+(b*i)+c)%mod;
			if(u>pqmin.top()) pqmin.push(u);
			else pqmax.push(u);
			ll x=pqmin.size();ll y=pqmax.size();
			if(abs(x-y)>1)
			{
				if(x>y) 
				{
					ll temp=pqmin.top();pqmin.pop();pqmax.push(temp);
				}
				else
				{
					ll temp=pqmax.top();pqmax.pop();pqmin.push(temp);
				}
			}
			ans+=u;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
