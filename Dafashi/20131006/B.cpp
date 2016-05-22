#include <iostream>
using namespace std;
int a[210][210],n,m,b[210][210],tmp=0,ans=1e9;
void work();
main()
{
	cin>>n>>m;
	for (int i=1;i<=3;i++)
	 for (int j=1;j<=3;j++)
	  a[i][j]=0;
	a[1][1]=1;
	a[2][3]=1;
	a[3][2]=1;
	work();
	for (int i=1;i<=3;i++)
	 for (int j=1;j<=3;j++)
	  a[i][j]=0;
	a[1][3]=1;
	a[2][2]=1;
	a[3][1]=1;
	work();
	for (int i=1;i<=3;i++)
	 for (int j=1;j<=3;j++)
	  a[i][j]=0;
	a[1][2]=1;
	a[2][1]=1;
	a[3][3]=1;
	work();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		 if (b[i][j]==1) cout<<'#';
		 else cout<<'0';
		cout<<endl;
	}
}
void work()
{
	tmp=0;
	for (int j=4;j<=m;j++)
	{
		for (int i=1;i<=3;i++)
		  a[i][j]=a[i][j-3];
	}
	for (int i=4;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		  a[i][j]=a[i-3][j];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		 if (a[i][j]==1) tmp++;
	}
	if (tmp<ans) 
	{
		ans=tmp;
	  for (int i=1;i<=n;i++)
	  {
		for (int j=1;j<=m;j++)
		 b[i][j]=a[i][j];
	  }
    }
}
