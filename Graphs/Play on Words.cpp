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
ll a[27],b[27],visited[27];ll m[27][27];

void dfs(ll root)
{
	visited[root]=1;

	for(ll i=0;i<26;i++)
	{
		if(!visited[i])
		{
			if(m[root][i]==1)
			{
				dfs(i);	
			}	
		}
	}
}

bool connected()
{
	ll root;
	for(ll i=0;i<26;i++)
	{
		if(a[i]>0) root=i;	
	}
	dfs(root);
	for(ll i=0;i<26;i++)
	{
		if(!visited[i] && (a[i]>0 || b[i]>0)) return false;
	} 
	return true;
}

int main()
{
	fastIO
	ll t;cin>>t;
	while(t--)
	{
		ll n;cin>>n;
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));
		memset(m,0,sizeof(m));memset(visited,0,sizeof(visited));
		while(n--)
		{
			string temp;cin>>temp;ll x=temp[0]-'a';ll y=temp[temp.size()-1]-'a';
			a[x]+=1;b[y]+=1;m[x][y]=1;m[y][x]=1; 
		}
		ll ceq=0,cother=0,c1more=0,c1less=0;
		for(ll i=0;i<26;i++)
		{
			if(a[i]==b[i]) ceq+=1;
			else if(a[i]-b[i] == 1) c1more+=1;
			else if(b[i]-a[i] == 1) c1less+=1;
			else
			{
				c1more+=2;break;
			}
		}
		if(cother==0 && (ceq==26 || (ceq==24 && c1more==1 && c1less==1))) 
		{
			if(connected()) cout<<"Ordering is possible.\n";
			else cout<<"The door cannot be opened.\n";
		}
		else cout<<"The door cannot be opened.\n";
	}
	return 0;
}
