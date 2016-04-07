#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN=100100;
const int MAXM=200100;
struct EDGE
{
    int x,y,z;
} e[MAXM];
int n,m,Q,tot;
map <int,int> g[MAXN],f[MAXN];

int cmp(const EDGE &x,const EDGE &y)
{
    if (x.x!=y.x) return x.x<y.x;
    return x.y<y.y;
}

void init()
{
    int x,y;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        g[i].clear();
        f[i].clear();
    }
    
    if (m==0) return ;
    
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if (x>y) swap(x,y);
        e[i].x=x; e[i].y=y;
    }
    sort(e+1,e+m+1,cmp);
    tot=1;
    e[1].z=1;
    for (int i=2;i<=m;i++)
    {
        if (e[i].x==e[i-1].x && e[i].y==e[i-1].y) e[tot].z++;
        else
        {
            tot++;
            e[tot].x=e[i].x;
            e[tot].y=e[i].y;
            e[tot].z=1;
        }
    }
    
    for (int i=1;i<=tot;i++)
    {
        g[e[i].x][e[i].y]=e[i].z;
        g[e[i].y][e[i].x]=e[i].z;
    }
}

void work()
{
    int x,y,z;
    cin>>Q;
    for (int i=1;i<=Q;i++)
    {
        scanf("%d%d",&x,&y);
        if (x==y)
        {
            printf("0 1\n");
            continue;
        }
        if (x>y) swap(x,y);
        if (g[x][y]!=0)
        {
            printf("1 %d\n",g[x][y]);
            continue;
        }
        g[x].erase(y);
        
        if (f[x][y]!=0)
        {
            if (f[x][y]==-1) printf("The pair of cities are not connected or too far away.\n");
            else printf("2 %d\n",f[x][y]);
            continue;
        }
        
        int ans=0;
        for (auto i:g[x])
        {
            z=i.first;
            if (g[z][y]==0)
            {
                g[z].erase(y);
                continue;
            }
            ans+=i.second*g[z][y];
        }
        
        if (ans==0) f[x][y]=-1;
        else f[x][y]=ans;
        

        if (f[x][y]==-1) printf("The pair of cities are not connected or too far away.\n");
        else printf("2 %d\n",f[x][y]);
        
    }
}

int main()
{
    int T;
    cin>>T;
    for (int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<":"<<endl;
        init();
        work();
    }
}