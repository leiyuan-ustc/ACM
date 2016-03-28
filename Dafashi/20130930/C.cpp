#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN=200010;
int n,m;
int a[MAXN],b[MAXN];
int f1[MAXN][20],g[MAXN][20];
bool used[MAXN*5];

void init_max()
{
    int tmp;
    for (int k=1;k<=20;k++)
    {
        tmp=1<<k;
        if (tmp>n) break;
        for (int i=1; i<=n; i++)
        {
            if (i+tmp-1>n) break;
            if (b[g[i][k-1]]>=b[g[i+tmp/2][k-1]]) g[i][k]=g[i][k-1];
            else g[i][k]=g[i+tmp/2][k-1];
        }
    }
}

int find_max(int l,int r)
{
    int k=log2(r-l+1);
    if (b[g[l][k]]>=b[g[r-(1<<(k))+1][k]]) return g[l][k];
    else return g[r-(1<<(k))+1][k];
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    int pt=1;
    for (int i=1;i<=n;i++)
    {
        used[a[i-1]]=0;
        while (pt<=n && used[a[pt]]==0) used[a[pt++]]=1;
        b[i]=pt-i;
        
        g[i][0]=i;
    }
    
    init_max();
    
    int x,y;
    int ans,pos,tmp;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        x++; y++;
        
        pos=find_max(x,y);
        ans=0;
        
        do
        {
            tmp=min(b[pos],y-pos+1);
            if (tmp<=ans) break;
            ans=tmp;
            if (b[pos]<=y-pos+1) break;
            if (x==pos) break;
            pos=find_max(x,pos-1);
        }
        while (1);
        
        printf("%d\n",ans);
    }
}