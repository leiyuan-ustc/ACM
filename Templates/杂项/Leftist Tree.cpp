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
        c[st][i]=ret;   //将b的st到i这段区间变为不下降序列所需的最小代价，d为前缀和
    }
}
