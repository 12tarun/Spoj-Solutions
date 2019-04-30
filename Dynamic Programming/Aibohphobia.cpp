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
string s1,s2; ll dp[6200][6200];
 
ll lcs(ll i,ll j,ll l1,ll l2)
{
    if(i>=l1 || j>=l2) return 0;
    if(dp[i][j]==-1)
    {
        if(s1[i]==s2[j]) dp[i][j]=1+lcs(i+1,j+1,l1,l2);
        else dp[i][j]=max(lcs(i+1,j,l1,l2),lcs(i,j+1,l1,l2));    
    }
    return dp[i][j];
}
 
int main() 
{
	fastIO
	ll t; cin>>t;
	while(t--)
	{
	    memset(dp,-1,sizeof(dp));
	    cin>>s1;ll l1=s1.size();s2="";for(ll i=l1-1;i>=0;i--) s2.pb(s1[i]);ll l2=s2.size();
	    ll ans=lcs(0,0,l1,l2);ans=l1-ans;
	    cout<<ans<<"\n";
	}
	return 0;
} 
