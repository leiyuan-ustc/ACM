#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int mov[8][4]={{0,-1},{-1,0},{0,1},{1,0},{1,-1},{-1,1},{1,1},{-1,-1}};
int n,m;
int sx,sy,ldx,ldy;
int a[100][100],b[100][100],c[100][100];
int q[10000][2],head,tail;
int dis[100][100];
char s[100];

void bfs(int dir)
{
    int xx,yy;
    head=tail=0;
    tail++;
    q[tail][0]=sx;
    q[tail][1]=sy;
    dis[sx][sy]=0;
    do
    {
        head++;
        for (int i=0;i<8;i++)
        {
            xx=q[head][0]+mov[i][0];
            yy=q[head][1]+mov[i][1];
            if (xx>=1 && xx<=n && yy>=1 && yy<=m)
                if (a[xx][yy]!=-1 && dis[xx][yy]==-1)
                {
                    if (b[xx][yy]==1 && mov[i][1]==-dir) continue;
                    dis[xx][yy]=dis[q[head][0]][q[head][1]]+1;
                    tail++;
                    q[tail][0]=xx;
                    q[tail][1]=yy;
                }
        }
    }
    while (head!=tail);
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        for (int j=1;j<=m;j++)
        {
            switch (s[j-1])
            {
                case '.':
                    a[i][j]=0;
                    break;
                    
                case '*':
                    sx=i; sy=j;
                    break;
                
                default:
                    a[i][j]=-1;
                    break;
            }
        }
    }
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]==-1)
            {
                ldx=i;
                ldy=j;
                break;
            }
    for (int i=ldx+1;i<=n;i++)
        b[i][ldy]=1;
    
    memset(dis,-1,sizeof(dis));
    bfs(-1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            c[i][j]=dis[i][j];
    
    
    
    memset(dis,-1,sizeof(dis));
    bfs(1);
    
    int ans=999999999;
    for (int i=ldx+1;i<=n;i++)
        ans=min(ans,c[i][ldy]+dis[i][ldy]);
    cout<<ans<<endl;
}