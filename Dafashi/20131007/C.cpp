#include <iostream>
using namespace std;
int a[1010][1010];
int main()
{
	int x,y,z,n,m,flag=0,k,r=0,ans,cc,count,p;
	cin>>n>>m;
	if ((n+m)&1!=0) 
	{
		cout<<0<<endl;
		return 0;
	}
	if (n<m) 
	{
		swap(n,m);
		flag=1;
	}
	cin>>k;
	for (int i=1;i<=k;i++)
	{
		cin>>x>>y>>z;
		if (flag==1) swap(x,y);
		a[x][y]=z;
	}
	cin>>cc;
	for (int i=1;i<=n;i++)
	{
		count=0;
		p=1;
	    for (int j=1;j<=m;j++)
	    {
	 	 if (a[i][j]!=0) count++;
	 	 p*=a[i][j];
	    }
	 	if (count==m) r++;
	 	if (p==1) 
	 	{
	 		cout<<0<<endl;
	 		return 0;
		}
    }
    p=m*n-m-n+1+r-k;
    ans=1;
    for (int i=1;i<=p;i++) ans=ans*2%cc;
    cout<<ans<<endl;
}
