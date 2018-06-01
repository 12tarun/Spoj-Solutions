#include<bits/stdc++.h>
using namespace std;
int main()
{
	int workers;
	cin>>workers;
	int a[2][workers];
	int i; int j;
	int min1 = 100001; int min2 = 100001; int min3 = 100001;
	for(i=0;i<=1;i++)
	{
		for(j=0;j<workers;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<workers;i++)
	{
		if(a[1][i] == 1)
		{
			if(a[0][i]<min1)
			{
				min1 = a[0][i];
			}
		}
		else if(a[1][i] == 2)
		{
			if(a[0][i]<min2)
			{
				min2 = a[0][i];
			}
		}
		else
		{
			if(a[0][i]<min3)
			{
				min3 = a[0][i];
			}
		}
	}
//	cout<<min1<<" "<<min2<<" "<<min3<<" ";
	int add = min1 + min2;
	if(add<min3)
	{
		cout<<add;
	}
	else
	{
		cout<<min3;
	}
	return 0;
} 
