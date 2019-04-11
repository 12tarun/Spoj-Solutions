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
#define fi first
#define se second
#define umap tr1::unordered_map
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std; 
map<string,ll> m;vector<string> yodas;vector<string> actual;ll cnt;ll n;vector<ll> a;

void merge(vector<ll> lft,vector<ll> rht,vector<ll> &x)
{
	ll i=0,j=0,k=0;
	while(i<lft.size() && j<rht.size())
	{
		if(lft[i]<rht[j])
		{
			x[k]=lft[i];
			i+=1;
		}
		else
		{
			x[k]=rht[j];
			j+=1;cnt+=(lft.size()-i); 
		}
		k+=1;
	}
	while(i<lft.size())
	{
		x[k]=lft[i];i+=1;k+=1;	
	} 
	while(j<rht.size())
	{
		x[k]=rht[j];j+=1;k+=1;	
	}	
}

void solve(vector<ll> &x)
{
	ll l = x.size(); if(l<2) return;
	ll mid = l/2;
	vector<ll> lft,rht;
	for(ll i=0;i<mid;i++) lft.pb(x[i]);
	for(ll i=mid;i<l;i++) rht.pb(x[i]);	
	solve(lft);
	solve(rht);
	merge(lft,rht,x);	
}

int main()
{
	fastIO
	ll t;cin>>t;
	while(t--)
	{
		cin>>n;
		m.clear();yodas.clear();actual.clear();a.clear();cnt=0;
		for(ll i=0;i<n;i++)
		{
			string temp;cin>>temp;yodas.pb(temp);
		}
		for(ll i=0;i<n;i++)
		{
			string temp;cin>>temp;actual.pb(temp);
			m[temp]=i+1;
		}
		for(ll i=0;i<n;i++) a.pb(m[yodas[i]]);
		solve(a);
		cout<<cnt<<"\n";
	}
	return 0;
}
