#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int MAXN=1010,MAXM=1010*1010;
int n,m;
vector <int> bcc[MAXN];
stack <int> s;
int coun,first[MAXN],nex[MAXM*2],tt[MAXM*2],ff[MAXM*2];
int pre[MAXN],cut[MAXN],bccno[MAXN];        //cut[i]==1 表明i为割点，bccno存储所在BCC编号，割点是公共点，BCC编号无意义
int dfs_clock,bcc_cnt;
int odd[MAXN],col[MAXN],g[MAXN][MAXN];
void init()
{
	coun=0;
	dfs_clock=0;
	bcc_cnt=0;
	memset(first,0,sizeof(first));
	memset(pre,0,sizeof(pre));
	memset(cut,0,sizeof(cut));
	memset(bccno,0,sizeof(bccno));
	memset(odd,0,sizeof(odd));
	memset(g,0,sizeof(g));
}
void add_edge(int x,int y)
{
	coun++;
	tt[coun]=y;
	ff[coun]=x;
	nex[coun]=first[x];
	first[x]=coun;
}
void build()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			if (g[i][j]==0 && i!=j)
				add_edge(i,j);
	}
}
int dfs(int u,int fa)
{
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	for (int k=first[u]; k!=0; k=nex[k])
	{
		if (pre[tt[k]]==0)
		{
			s.push(k);
			child++;
			int lowv=dfs(tt[k],u);
			lowu=min(lowu,lowv);
			if (lowv>=pre[u]) //若lowv>pre[u]说明该边是桥
			{
				cut[u]=1;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				while (1)
				{
					int x,y;
					x=ff[s.top()];
					y=tt[s.top()];
					s.pop();
					if (bccno[x]!=bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x);
						bccno[x]=bcc_cnt;
					}
					if (bccno[y]!=bcc_cnt)
					{
						bcc[bcc_cnt].push_back(y);
						bccno[y]=bcc_cnt;
					}
					if (x==u && y==tt[k]) break;
				}
			}
		}
		else if (pre[tt[k]]<pre[u] && tt[k]!=fa)
		{
			lowu=min(lowu,pre[tt[k]]);
		}
	}
	if (fa<0)
		if (child<=1) cut[u]=0;
		else cut[u]=1;
	return lowu;
}
void work()
{
	for (int i=1;i<=bcc_cnt;i++)
	{
		if (bcc[i].size()<3) continue;
		memset(col,0,sizeof(col));
		
		for (int j=0;j<bcc[i].size();j++)
			bccno[bcc[i][j]]=i;		
        }
}
int main()
{
	int x,y;
	while (1)
	{
		cin>>n>>m;
		if (n==0 && m==0) break;
		init();
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d",&x,&y);
			g[x][y]=g[y][x]=1;
		}
		build();
		
		for (int i=1;i<=n;i++)
			if (pre[i]==0) dfs(i,-1);
		
		work();
	}
}

//对于一棵树，使其变为双连通图最少增加的边数为：（度数为1的节点数＋1）／2
//如果一个双连通分量中存在一个奇圈，那么该双连通分量内的所有顶点都处在某个奇圈内。