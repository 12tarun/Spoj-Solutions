#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, a, b;
		scanf("%d%d%d",&n,&a,&b);
		int arr[n];
		int i; double p1, p2; int c1 = 0; int c2 = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;i++)
		{
			if(arr[i] == a)
			{
				c1++;
			}
			if(arr[i] == b)
			{
				c2++;
			}
		}
		p1 = c1/(double)n;
		p2 = c2/(double)n;
		double ans = p1*p2;
		printf("%f\n",ans);
	}
	return 0;
}
