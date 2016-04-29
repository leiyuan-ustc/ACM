#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
const int MAXN=10010,MAXM=50010;
int n,m;
int coun,first[MAXN],nex[MAXM],tt[MAXM];
int pre[MAXN],low[MAXN],id[MAXN],de[MAXN];
int vis[MAXN];
int dfs_clock,col;
stack <int> s;
vector <int> g[MAXN];
void dfs(int u)
{
    low[u]=pre[u]=++dfs_clock;
    s.push(u);
    for (int k=first[u]; k!=0; k=nex[k])
    {
        if (pre[tt[k]]==0) dfs(tt[k]);
        if (id[tt[k]]==0) low[u]=min(low[u],low[tt[k]]);
    }
    
    if (low[u]==pre[u])
    {
        col++;
        id[u]=col;
        while (s.top()!=u)
        {
            id[s.top()]=col;
            s.pop();
        }
        s.pop();
    }
}
void add_edge(int x,int y)
{
    coun++;
    tt[coun]=y;
    nex[coun]=first[x];
    first[x]=coun;
}
int main()
{
    int x,y;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    
    dfs(1);
    for (int i=1;i<=n;i++)
        if (pre[i]==0)
            dfs(i);
}