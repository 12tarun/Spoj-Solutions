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
	while(true)
	{
		ll n;cin>>n;if(n==0)break;
		ll a[n];rep(i,0,n-1,1)cin>>a[i];
		stack<pl> s;ll maxarea=a[0];s.push(mp(a[0],0));
		rep(i,1,n-1,1)
		{
			ll area=0;
			while(a[i]<s.top().first)
			{
				ll x=s.top().first;s.pop();
				if(s.empty())
				{
					area=x*i;
					if(area>maxarea)maxarea=area;
					break;
				}
				else
				{
					area=x*(i-s.top().second-1);
					if(area>maxarea)maxarea=area;
				}
			}
			s.push(mp(a[i],i));	
		}
		while(!s.empty())
		{
			ll area=0;
			ll x=s.top().first;s.pop();
			if(s.empty())
			{
				area=x*n;
			}
			else
			{
				area=x*(n-s.top().second-1);
			}
			if(area>maxarea)maxarea=area;
		}
		cout<<maxarea<<"\n";	
	}
	return 0;
} 
