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
		ll n;pq maxim;rpq minim;
		while(true)
		{
			cin>>n;
			if(n==0) break;
			else if(n>0)
			{
				if(maxim.size()==0 && minim.size()==0) minim.push(n);
				else
				{
					if(n<=minim.top()) maxim.push(n);
					else minim.push(n); 
				} 
				ll x=maxim.size();ll y=minim.size();
				if(abs(x-y) > 1) 
				{
					if(x>y)
					{
						minim.push(maxim.top());maxim.pop();
					}
					else
					{
						maxim.push(minim.top());minim.pop();
					}
				}
			}
			else
			{
				if(maxim.size()>=minim.size())
				{
					cout<<maxim.top()<<"\n";
					maxim.pop();
				}
				else
				{
					cout<<minim.top()<<"\n";
					minim.pop();	
				}
			}
		}
	}
	return 0;
} 
