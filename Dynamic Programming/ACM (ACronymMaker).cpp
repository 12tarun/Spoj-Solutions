#include<bits/stdc++.h> 
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
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
vector<string> insig;vector<vector<string> > abph(200);ll f,abphlen;ll wl[200],cumwl[200];ll dp[200][200];
 
ll solve(ll i,ll j,ll si,ll row)
{
	if(i==f)
	{
		if(j==abphlen) return 1;
		return 0;
	}
	if(j==abphlen) return 0;
	
	ll pos=cumwl[j-1]+si;
	
	if(dp[i][pos]==(-1))
	{
		ll ans=0;
		for(ll x=si;x<abph[row][j].size();x++)
		{
			if(abph[row][j][x]==(abph[row][0][i]+32))
			{
				if(x!=(abph[row][j].size()-1)) ans+=solve(i+1,j,x+1,row);
				ans+=solve(i+1,j+1,0,row);
			} 
		}
		dp[i][pos] = ans;
	}
	return dp[i][pos];
}
 
bool search(string x,ll s,ll e)
{
	while(s<=e)
	{
		ll mid=(s+e)/2;
		if(x<insig[mid]) e=mid-1;
		else if(x>insig[mid]) s=mid+1;
		else return true;
	}
	return false;
}
 
int main() 
{
	fastIO
	ll n;
	while(true)
	{
		cin>>n;if(n==0) break;
		insig.clear();for(ll i=0;i<200;i++) abph[i].clear();
		for(ll i=0;i<n;i++)
		{
			string s;cin>>s;insig.pb(s);
		}
		ll insiglen=insig.size();
		sort(insig.begin(),insig.end());	
		ll j=0;cin.ignore();
		while(true)
		{
			string s;getline(cin,s);
			ll len=s.size();string temp="";
			for(ll i=0;i<len;i++)
			{
				if(s[i]==' ')
				{
					bool x = search(temp,0,insiglen-1);
					if(x==false) abph[j].pb(temp);
					temp="";
				} 
				else if(i==(len-1))
				{
					temp.pb(s[i]);
					bool x = search(temp,0,insiglen-1);
					if(x==false) abph[j].pb(temp);
					temp="";
				}
				else temp.pb(s[i]); 	
			}
			if(abph[j].size()==2 && (abph[j][0]=="LAST" && abph[j][1]=="CASE"))
			{
				abph[j].clear();break;
			}
			j+=1;	
		}
		j=0;
		while(abph[j].size()!=0)
		{
			memset(dp,-1,sizeof(dp));
			f=abph[j][0].size();abphlen=abph[j].size();cumwl[0]=0;
			for(ll k=1;k<abphlen;k++) wl[k]=abph[j][k].size();
			for(ll k=1;k<abphlen;k++) cumwl[k]=cumwl[k-1]+wl[k];
			ll ans=solve(0,1,0,j);
			if(ans==0) cout<<abph[j][0]<<" is not a valid abbreviation\n";
			else cout<<abph[j][0]<<" can be formed in "<<ans<<" ways\n";
			j+=1;
		}
	}
	return 0;
} 
