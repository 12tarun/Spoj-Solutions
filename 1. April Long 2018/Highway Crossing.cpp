#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
    scanf("%d",&t);
	while(t--)
	{
		int n;
		double s, y;
		scanf("%d",&n);
		scanf("%lf",&s);
		scanf("%lf",&y);
		double v[n]; double d[n]; double p[n]; double c[n];int i;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&v[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&d[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&p[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&c[i]);
		}
	//	cout<<y<<" "<<s<<" "<<time;
		double time = y/s;
		double t = 0; // initial time
		int j; double q;
		for(i=0;i<n;i++)
		{
		//	cout<<time<<" ";
			if((p[i]>=0 && d[i]==0)||(p[i]<=0 && d[i]==1))
			{
		//		cout<<(abs(p[i])/v[i])<<" "<<time<<" ";
				if((abs(p[i])/v[i])-(time)<=(pow(10,-6)))
				{
					q = (abs(p[i])+abs(c[i]))/v[i];
					t = t + time + q;
		//			cout<<t<<"yes";
					for(j=i+1;j<n;j++)
					{
						if(d[j] == 0)
						{
							p[j] = p[j] - ((q+time)*v[j]);
					//		cout<<p[j]<<"yes";
						}
						else
						{
							p[j] = p[j] + ((q+time)*v[j]);
						}
					}
				}
				else
				{
					t = t + time;
					for(j=i+1;j<n;j++)
					{
						if(d[j] == 0)
						{
							p[j] = p[j] - (time*v[j]);
						}
						else
						{
							p[j] = p[j] + (time*v[j]);
						}
					}
				}
			}
			else if((p[i]<0 && (p[i]+c[i])>0)||(p[i]>0 && (p[i]-c[i])<0)) //train x = 0 pr hai aadhi
			{
				q = (c[i]-abs(p[i]))/v[i];
				t = t + time + q;
				for(j=i+1;j<n;j++)
				{
					if(d[j] == 0)
					{
						p[j] = p[j] - ((q+time)*v[j]);
					}
					else
					{
						p[j] = p[j] + ((q+time)*v[j]);
					}
				}
			}
			else
			{
				t = t + time;
				for(j=i+1;j<n;j++)
				{
					if(d[j] == 0)
					{
						p[j] = p[j] - (time*v[j]);
					}
					else
					{
						p[j] = p[j] + (time*v[j]);
					}
				}
			}
		}
		printf("%lf\n",t);
	}
	return 0;
} 
