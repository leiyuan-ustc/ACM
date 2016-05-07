#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;
struct NODE
{
    int val;
    int dist;
    int size;
    int l,r;
};
NODE tree[1010];
int sp;

int GetDist(int A)
{
    if (A==0) return -1;
    else return tree[A].dist;
}

int merge(int A,int B)
{
    if (A==0) return B;
    if (B==0) return A;
    if (tree[A].val<tree[B].val) swap(A,B);
    tree[A].size+=tree[B].size;
    tree[A].r=merge(tree[A].r,B);
    if (GetDist(tree[A].r) > GetDist(tree[A].l)) swap(tree[A].l,tree[A].r);
    tree[A].dist=GetDist(tree[A].r)+1;
    return A;
}

void del(int &A)
{
    if (A==0) return ;
    int B,C;
    B=tree[A].l;
    C=tree[A].r;
    B=merge(B,C);
    A=B;
}

int build(int val)
{
    int tmp;
    tmp=++sp;
    tree[tmp].l=tree[tmp].r=0;
    tree[tmp].val=val;
    tree[tmp].size=1;
    return tmp;
}

int n,m;
int a[1010],b[1010];
int f[1010][20],c1[1010][1010],c2[1010][1010],cost[1010][1010],d[1010];


int s[1010];
int rg[1010];
int sum[1010];
int ss[1010];
int top;

void init(int st,int c[1010][1010])
{
    int now,tmp;
    int ret;
    int tot,t,t1;
    
    top=0;
    sp=0;
    
    
    ret=0;
    for (int i=st;i<=n;i++)
    {
        now=build(b[i]);
        tot=1;
        t1=b[i];
        
        while (top>=1)
        {
            tmp=s[top];
            if (tree[tmp].val>tree[now].val)
            {
                ret-=sum[top];
                tot+=rg[top];
                t1+=ss[top];
                top--;
                now=merge(now,tmp);
                while (tree[now].size > (tot+1)/2)
                {
                    t1-=tree[now].val;
                    del(now);
                }
            }
            else break;
        }
        t=((d[i]-d[i-tot]-t1) - ((tot-tree[now].size)*tree[now].val)) + ((tree[now].size*tree[now].val)-t1);
        top++;
        s[top]=now;
        rg[top]=tot;
        ss[top]=t1;
        sum[top]=t;
        ret+=t;
        c[st][i]=ret;
    }
    
    
}

int main()
{
    while (1)
    {
        cin>>n>>m;
        //n=1000; m=10;
        if (n==0 && m==0) break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            //a[i]=0;
            b[i]=a[i]-i;
            d[i]=d[i-1]+b[i];
        }
        for (int i=1;i<=n;i++)
            init(i,c1);
        
        for (int i=1;i<=n;i++)
        {
            b[i]=a[n-i+1]-i;
            d[i]=d[i-1]+b[i];
        }
        
        for (int i=1;i<=n;i++)
            init(i,c2);
        
        for (int i=1;i<=n;i++)
            for (int j=i;j<=n;j++)
            {
                //cout<<i<<' '<<j<<' '<<c1[i][j]<<' '<<c2[i][j]<<endl;
                cost[i][j]=min(c1[i][j],c2[n-j+1][n-i+1]);
            }
        
        
        
        f[1][1]=0;
        for (int i=2;i<=n;i++)
        {
            f[i][1]=cost[1][i];
            for (int j=2;j<=m;j++)
            {
                if (j>i) break;
                f[i][j]=2147483647;
                for (int k=j-1;k<i;k++)
                {
                    f[i][j]=min(f[i][j],f[k][j-1]+cost[k+1][i]);
                }
            }
        }
        
        cout<<f[n][m]<<endl;
    }
}