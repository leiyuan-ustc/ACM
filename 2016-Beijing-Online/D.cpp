#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const int MAXK=1000000000;
using namespace std;
int dp[2][10][10][10][1010],kind[2][10][10][10][1010];
int N;
int C;
int T;
struct teamate
{
	char s[100];
	int v,c;
}a[510];
bool com(teamate a,teamate b)
{
	return a.v>b.v;
}
main()
{
	scanf("%d",&T);
	while (T-->0)
	{
		int ans=-1,ansc=MAXK,ans2=0;
		scanf("%d",&N);
		for (int i=1;i<=N;i++) scanf("%s%d%d",a[i].s,&a[i].v,&a[i].c);
		sort(a+1,a+1+N,com);
		//for (int i=1;i<=N;i++) cout<<a[i].s<<" "<<a[i].v<<" "<<a[i].c<<endl;
		scanf("%d",&C);
		for (int i=0;i<=1;i++)
		 for (int j=0;j<=5;j++)
		  for (int k=0;k<=5;k++)
		   for (int l=0;l<=3;l++)
		    for (int p=0;p<=C;p++)
		    {
		    	dp[i][j][k][l][p]=-1;
		    	kind[i][j][k][l][p]=0;
			}
		dp[0][0][0][0][0]=0;
		kind[0][0][0][0][0]=1;
		for (int u=1;u<=N;u++)
		{
		 for (int j=5;j>=0;j--)
		  for (int k=5;k>=0;k--)
		   for (int l=3;l>=0;l--)
			for (int i=1;i>=0;i--)
			 if (i+j+k+l<11)
			 for (int p=C-a[u].c;p>=0;p--)
			  if (dp[i][j][k][l][p]!=-1)
			  {	    	
			    int i2,j2,k2,l2,p2;
			    i2=i,j2=j,k2=k,l2=l,p2=p+a[u].c;
			    if (strcmp(a[u].s,"Goalkeeper")==0) i2+=1;
			    else if (strcmp(a[u].s,"Defender")==0) j2+=1;
			    else if (strcmp(a[u].s,"Midfielder")==0) k2+=1;
			    else if (strcmp(a[u].s,"Forward")==0) l2+=1;
			    if (i2>1||j2>5||k2>5||l2>3) continue;
			    if (i==0&&j==0&&k==0&&l==0)
			    {
			    	if (dp[i2][j2][k2][l2][p2]<dp[i][j][k][l][p]+a[u].v*2)
			    	{
			    		dp[i2][j2][k2][l2][p2]=dp[i][j][k][l][p]+a[u].v*2;
			    		kind[i2][j2][k2][l2][p2]=min(kind[i][j][k][l][p],MAXK);
					}
					else if (dp[i2][j2][k2][l2][p2]==dp[i][j][k][l][p]+a[u].v*2)
					{
						kind[i2][j2][k2][l2][p2]=min(MAXK,kind[i][j][k][l][p]+kind[i2][j2][k2][l2][p2]);
					}
				}
				else
				{
					if (dp[i2][j2][k2][l2][p2]<dp[i][j][k][l][p]+a[u].v)
			    	{
			    		dp[i2][j2][k2][l2][p2]=dp[i][j][k][l][p]+a[u].v;
			    		kind[i2][j2][k2][l2][p2]=min(kind[i][j][k][l][p],MAXK);
					}
					else if (dp[i2][j2][k2][l2][p2]==dp[i][j][k][l][p]+a[u].v)
					{
						kind[i2][j2][k2][l2][p2]=min(MAXK,kind[i][j][k][l][p]+kind[i2][j2][k2][l2][p2]);
					}
				}
			  }
 	    }
 	    for (int j=3;j<=5;j++)
		  for (int k=2;k<=5;k++)
		   for (int l=1;l<=3;l++)
		    if (j+k+l+1==11)
		     for (int p=0;p<=C;p++)
		      if (dp[1][j][k][l][p]>ans)
		      {
		     	ans=dp[1][j][k][l][p];
		     	ans2=kind[1][j][k][l][p];
		     	ansc=p;
		      }
		      else if (dp[1][j][k][l][p]==ans)
		      {
		      	if (p<ansc) 
		      	{
		      		ans2=kind[1][j][k][l][p];
		      		ansc=p;
				}
		      	else
		      	if (p==ansc)
		      	{
		      		ans2=min(MAXK,ans2+kind[1][j][k][l][p]);
				}
			  }
 	    cout<<ans<<" "<<ansc<<" "<<ans2<<endl;
 	}
}
