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
vector<vl> G(400);ll visited[400];stack<ll> stk;

void dfs(ll node)
{
	visited[node]=1;
	for(ll i=0;i<G[node].size();i++)
	{
		if(!visited[G[node][i]])
		{
			dfs(G[node][i]);
		} 
	}
	stk.push(node);
}

int main()
{
	fastIO
	ll t;cin>>t;
	for(ll h=1;h<=t;h++)
	{
		for(ll i=0;i<400;i++)
		{
			G[i].clear();visited[i]=0;
		}
		ll steps;cin>>steps;map<string,ll> m;
		vector<vector<string> > v(steps-1);ll j=0;
		for(ll i=0;i<steps-1;i++)
		{
			string s1,s2;cin>>s1>>s2;
			v[i].pb(s1);v[i].pb(s2);
			if(m.find(s1)==m.end()) 
			{
				m[s1]=j;j+=1;
			}
			if(m.find(s2)==m.end()) 
			{
				m[s2]=j;j+=1;
			}
		}
		for(ll i=0;i<steps-1;i++)
		{			
			G[m[v[i][0]]].pb(m[v[i][1]]);
		}
		for(ll i=0;i<j;i++)
		{
			if(!visited[i]) dfs(i);
		}	
		cout<<"Scenario #"<<h<<":\n";
		while(!stk.empty())
		{
			ll x=stk.top();stk.pop();
			map<string,ll>:: iterator itr;
			for(itr=m.begin();itr!=m.end();itr++)
			{
				if(itr->se == x)
				{
					cout<<itr->fi<<"\n";break;
				} 
			}
		}
		cout<<"\n";	
	}
	return 0;
}
