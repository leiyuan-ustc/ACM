const int N=1010;
bool flag[N],a[N][N];
int ans,cnt[N],group[N],n,vis[N];
int m;
bool dfs(int u,int pos)
{
    int i,j;
    for(i=u+1;i<=n;i++)
    {
        if(cnt[i]+pos<=ans) return 0;//该剪枝可能有问题
        if(a[u][i])
        {

            for(j=1;j<=pos;j++)
                if(!a[i][vis[j]]) break;
            if(j==pos+1)
            {     
                vis[pos+1]=i;
                if(dfs(i,pos+1)) return 1;
            }
        }
    }
    
    if(pos>ans)
    {
        for(i=1;i<=pos;i++)
            group[i]=vis[i]; 
        ans=pos;
        return 1;
    }
    
    return 0;
}
void maxclique()
{
    ans=-1;
    for(int i=n;i>=1;i--)
    {
        vis[1]=i;
        dfs(i,1);
        cnt[i]=ans;
    }
}