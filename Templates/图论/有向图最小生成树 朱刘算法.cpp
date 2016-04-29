const int MAXN=110;
const int MAXM=110*110;
const double MAX_VAL=99999999;
struct Directed_MST
{
    int n,m;
    int root;
    
    struct edge
    {
        int x,y;
        double l;
    } e[MAXM];
    
    void init(int x,int r)
    {
        n=x;
        root=r;
        m=0;
    }
    
    void add_edge(int x,int y,double val)
    {
        m++;
        e[m].x=x;
        e[m].y=y;
        e[m].l=val;
    }
    
    double calc_MST()
    {
        double ans=0;
        double inlen[MAXM];
        int pre[MAXN];
        int mark[MAXN];
        int vis[MAXN];
        int cnt;
        
        while (1)
        {
            for (int i=1;i<=n;i++)
                inlen[i]=MAX_VAL;
            
            for (int i=1;i<=m;i++)
            {
                if (e[i].l<inlen[e[i].y] && e[i].x!=e[i].y)
                {
                    pre[e[i].y]=e[i].x;
                    inlen[e[i].y]=e[i].l;
                }
            }
            
            
            for (int i=1;i<=n;i++)
                if (i!=root && inlen[i]==MAX_VAL) return -1;
            
            inlen[root]=0;
            cnt=0;
            memset(vis,-1,sizeof(vis));
            memset(mark,-1,sizeof(mark));
            
            for (int i=1;i<=n;i++)
            {
                ans+=inlen[i];
                int v=i;
                while (vis[v]!=i && mark[v]==-1 && v!=root)
                {
                    vis[v]=i;
                    v=pre[v];
                }
                
                if (v!=root && mark[v]==-1)
                {
                    cnt++;
                    for (int u=pre[v];u!=v;u=pre[u])
                        mark[u]=cnt;
                    mark[v]=cnt;
                }
            }
            
            if (cnt==0) break;
            
            for (int i=1;i<=n;i++)
                if (mark[i]==-1)
                    mark[i]=++cnt;
            
            for (int i=1;i<=m;i++)
            {
                if (mark[e[i].x]!=mark[e[i].y])
                    e[i].l-=inlen[e[i].y];
                e[i].x=mark[e[i].x];
                e[i].y=mark[e[i].y];
            }
            
            n=cnt;
            root=mark[root];
        }
        return ans;
    }
    
} G;

//（1）从源点出发DFS，若无法到达所有点，最小生成树不存在，直接返回；
//（2）找每个结点的最小权入边；
//（3）若存在环，将同一环上所有结点进行缩点，对于指向该环内某点的边，将其权值减去该点的最小入边权，重复（2）；若无环，则树已建成。

//不定根的题目，只要虚拟一个根连所有的点的权为边权总和+1，最后的结果减去(边权+1)即可。另外对于求根标号，只要搜索被选中的虚边就可以判断了。与虚根相连的点即为原本的实根！
//如果选择了俩条或俩条以上的与虚根相连的边，则不存在对应的最小树形图

