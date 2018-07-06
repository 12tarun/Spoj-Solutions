#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string ans = "1";
		for(int i=2;i<=n;i=i+2)
		{
			ans.push_back('0');
		}
		cout<<"1"<<" "<<ans<<"\n";
	}
	return 0;
}
