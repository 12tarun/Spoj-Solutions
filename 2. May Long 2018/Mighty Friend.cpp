#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		int a[n];
		int to = 0; 
		int mo = 0;
		int l;
		if(n%2 == 0)
		{
			l = n/2;                             
		}
		else
		{
			l = n/2 + 1;
		}
		int b[l]; 
		int c[n/2];
		int i;
		int x = 0; 
		int y = 0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(i%2 == 0)
			{
				mo = mo + a[i];
				b[x] = a[i];
				x++;
			}
			else
			{
				to = to + a[i];
				c[y] = a[i];
				y++;
			}
		}
		if(to>mo)
		{
			cout<<"YES\n";
		}
		else if(mo>=to && k==0)
		{
			cout<<"NO\n";
		}
		else
		{
			int h = 0;
			int zz = l;
			sort(b, b+zz);
			sort(c, c+(n/2));
			int z = 0;
			int temp;
			for(i=1;i<=k;i++)
			{
				temp = b[zz-1];
				b[zz-1] = c[z];
				c[z] = temp;
				mo = mo - c[z] + b[zz-1];
				to = to - b[zz-1] + c[z];
				if(to>mo)
				{
					h = 1;
					cout<<"YES\n";
					break;
				}
				if(z == ((n/2)-1))
				{
					break;
				}
				z++;
				zz--;
			}
			if(h!=1)
			{
				cout<<"NO\n";
			}			
	    }			
	}
	return 0;
}
