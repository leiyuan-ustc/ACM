#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int x[20010],y[20010],t,n,m,i,j,ans[200010],s,w;
main()
{
	cin>>t;
	while (t-->0)
	{
		cin>>n>>m;
		if (n>20000)
		{
			for (i=1;i<=n;i++) ans[i]=1;
			for (i=1;i<=m;i++)
			{
				cin>>x[i]>>y[i];
			}
			cin>>s;
			for (i=1;i<=m;i++)
			{
				if (x[i]==s) ans[y[i]]=2;
				else if (y[i]==s) ans[x[i]]=2;
			}
	        bool flag=false;
			for (i=1;i<=n;i++)
			{
				if (i==s) continue;
				if (flag) cout<<" ";
				flag=true;
			    cout<<ans[i];
		    }
		    cout<<endl;
		}
		else
		{
			vector<vector<bool> > f(n+1, vector<bool>(n+1, true));
			for (i=1;i<=n;i++) 
			{
				ans[i]=-1;
			}
		   	for (i=1;i<=m;i++)
		   	{
		   		cin>>x[i]>>y[i];
		   		f[x[i]][y[i]]=false;
		   		f[y[i]][x[i]]=false;
			}
			cin>>s;
			queue<int> q;
		   	q.push(s);
		   	ans[s]=0;
		   	while (!q.empty())
		   	{
		   		w=q.front();
		   		q.pop();
		   		for (i=1;i<=n;i++)
		   		 if (f[w][i]&&ans[i]==-1)
		   		 {
		   		 	ans[i]=ans[w]+1;
		   		 	q.push(i);
				 }
			}
	        bool flag=false;
			for (i=1;i<=n;i++)
			{
				if (i==s) continue;
				if (flag) cout<<" "; 
				flag=true;
			    cout<<ans[i];
		    }
		    cout<<endl;
		}
	}
}
