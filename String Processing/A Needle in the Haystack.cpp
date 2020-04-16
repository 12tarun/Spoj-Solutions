#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vl vector<ll>
#define pl pair<ll,ll>
#define pq priority_queue<ll>
#define rpq priority_queue<ll, vl, greater<ll> > 
#define umap tr1::unordered_map
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed<<setprecision(10);
using namespace std;
using namespace __gnu_pbds; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pset;
ll pref[1000000];

void calPrefix(string &s, ll len)
{
	ll j = 0;
	pref[0] = j;
	for(ll i = 1; i < len; i++)
	{
		while(j > 0 && s[j] != s[i])
		{
			j = pref[j - 1];
		}
		if(s[i] == s[j]) j += 1;
		pref[i] = j;	
	} 
}

int main()
{
	fastIO
	ll cmplen;
	while(cin>>cmplen)
	{
		string cmp, s;
		cin>>cmp>>s;
		calPrefix(cmp, cmplen);
		vl ans;
		ll slen = s.size();
		ll cmpi = 0, si = 0;
		while(si < slen)
		{
			if(s[si] == cmp[cmpi])
			{
				si += 1;
				cmpi += 1;
			}
			else
			{
				if(cmpi == 0)
				{
					si += 1;
				}
				else
				{
					cmpi = pref[cmpi - 1];
				}
			}
			if(cmpi == cmplen)
			{
				ans.pb(si - cmplen);
			}
		}
		ll anslen = ans.size();
		for(ll i = 0; i < anslen; i++)
		{
			cout<<ans[i]<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
