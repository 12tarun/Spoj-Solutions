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
 
ll maxPoss(string s,ll len)
{
	ll a[len+1]={0}; a[0]=a[1]=1;
	ll i=2;
	while(i<=len)
	{
		a[i]=0;	
	    ll c1 = s[i-2]-'0', c2 = s[i-1]-'0';
		if(c1==1 || (c1==2 && c2<=6)) a[i] += a[i-2];
		if(c2!=0) a[i] += a[i-1];
		i+=1;
	}
	return a[len];
}
 
int main()
{
	fastIO
	string n;
	while(cin>>n)
	{
		if(!n.compare("0")) return 0;
		ll len=n.size(); ll ans;
		if(len==1) ans=1;
		else ans=maxPoss(n,len);
		cout<<ans<<"\n";	
	} 	
	return 0;
} 
