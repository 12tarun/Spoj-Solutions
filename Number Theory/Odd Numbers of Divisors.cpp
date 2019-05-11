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
ll d[100010]={0};vector<vl> v(100010);

ll numdiv(ll n)
{
	ll cnt=0,divs=1;
	while(n%2==0)
	{
		cnt+=1;n/=2;
	}
	divs*=(2*cnt+1); 
	repe(i,3,sqrt(n),2)
	{
		cnt=0;
		while(n%i==0)
		{
			cnt+=1;n/=i;
		}
		divs*=(2*cnt+1); // takes out all factors of n*n through powers of prime factors
	}
	if(n>1) divs*=3; // means n is prime
	return divs;
}
 
int main()
{
	fastIO
	rep(i,1,100001,1)
	{
		d[i]=numdiv(i);
		v[d[i]].pb(i); 
	}
	ll t;cin>>t;
	while(t--)
	{
		ll k,l,h;cin>>k>>l>>h;
	    ll pos1 = upper_bound(v[k].begin(),v[k].end(),(ll)sqrt(h)) - v[k].begin() - 1;  //<=high
        ll pos2 = upper_bound(v[k].begin(),v[k].end(),(ll)(sqrt(l)-1e-8)) - v[k].begin() -1; //<=low-1
        cout<<pos1-pos2<<"\n";
	}
	return 0;
} 
