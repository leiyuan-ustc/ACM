int coun,first[MAXN],next1[MAXN*2],tt[MAXN*2];
int p[MAXN][20],deep[MAXN];
int add_edge(int x,int y)
{
	coun++;
	tt[coun]=y;
	next1[coun]=first[x];
	first[x]=coun;
}
int build(int x)
{
	v[x]=1;
	for (int k=first[x];k!=0;k=next1[k])
	{
		if (v[tt[k]]==0)
		{
			deep[tt[k]]=deep[x]+1;
			p[tt[k]][0]=x;
			build(tt[k]);
		}
	}
}
int init_2k()
{
	for (int j=1;(1<<j)<=n;j++)
		for (int i=1;i<=n;i++)
			if (p[i][j-1]!=0)
				p[i][j]=p[p[i][j-1]][j-1];
}
int lca(int x,int y)
{
	int i,j;
	if (deep[x]<deep[y]) swap(x,y);
	for (i=0;(1<<i)<=deep[x];i++);
	i--;
	
	for (j=i;j>=0;j--)
		if (deep[x]-(1<<j)>=deep[y])
			x=p[x][j];
			
	if (x==y) return x;
	
	for (j=i;j>=0;j--)
	{
		if (p[x][j]!=0 && p[x][j]!=p[y][j])
		{
			x=p[x][j];
			y=p[y][j];
		}
	}
	
	return p[x][0];
}
