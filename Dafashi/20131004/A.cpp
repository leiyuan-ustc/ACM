#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct path
{
	int x,y,w,d;
}a[10010];
struct thing
{
	int c,d;
}b[1010],p[1010][10010];
int f[1010],m,n,c1,c2,q1,q2,sum=0,num=0,s=0;
bool g[1010][10010];
bool com(path e1,path e2)
{
	return e1.w<e2.w;
}
bool com2(thing e1,thing e2)
{
	return e1.d<e2.d;
}
int find(int v)
{
	if (f[v]!=v) f[v]=find(f[v]);
	return f[v];
}
void dfs(int i,int j)
{
	if (i>1) dfs(i-1,p[i][j].d);
	cout<<b[i].d<<" "<<p[i][j].c<<endl;
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++) 
	{
		cin>>a[i].x>>a[i].y>>a[i].w;
		a[i].d=i;
	}
	cin>>c1>>q1>>c2>>q2;
	if (n==1) 
	{
		cout<<0<<endl;
		return 0;
	}
    sort(a+1,a+1+m,com);
    //for (int i=1;i<=m;i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].w<<" "<<a[i].d<<endl;
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=m;i++)
    if (find(a[i].x)!=find(a[i].y))
    {
    	f[find(a[i].x)]=find(a[i].y);
    	b[++num].d=a[i].d;
    	b[num].c=a[i].w;
    	sum+=b[num].c;
	}
	//cout<<num<<" "<<sum<<endl;
	if (num!=n-1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	sort(b+1,b+n,com2);
	//for (int i=1;i<=n-1;i++) cout<<b[i].c<<" "<<b[i].d<<endl;
	g[0][0]=true;
	for (int i=1;i<=n-1;i++)
	{
	 for (int j=0;j<=q1;j++)
	  if (j-b[i].c>=0 && g[i-1][j-b[i].c])
	  {
	  	p[i][j].d=j-b[i].c;
	  	p[i][j].c=5;
	  	g[i][j]=true;
	  }
	  else
	  if (s-j+b[i].c<=q2 && g[i-1][j])
	  {
	  	p[i][j].d=j;
	  	p[i][j].c=6;
	  	g[i][j]=true;
	  }
	  else g[i][j]=false;
	 s+=b[i].c;
    }
    if (c1<c2) 
    {
     for (int j=q1;j>=0;j--) 
      if (g[n-1][j]) 
	  {
	    cout<<c1*j+c2*(sum-j)<<endl;
	    dfs(n-1,j);
	    return 0;
	  }
    }
    else 
    {
     for (int j=0;j<=q1;j++)
      if (g[n-1][j])
      {
      	cout<<c1*j+c2*(sum-j)<<endl;
      	dfs(n-1,j);
      	return 0;
	  }
	}
	cout<<"Impossible"<<endl;
}
