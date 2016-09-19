#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int q[400010],p[400010],tree[400010],a[100010];
void build(int v,int l,int r)
{
    p[v]=l;q[v]=r;
    if (l==r)
    {
        scanf("%d",&a[l]);
        tree[v]=l;
        return;
    }
    int mid=(l+r)/2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    if (a[tree[v*2]]<a[tree[v*2+1]]) tree[v]=tree[v*2];
    else tree[v]=tree[v*2+1];
}
int find(int v,int l,int r,int x)
{
    if (a[tree[v]]>x) return -1;
    if (p[v]==q[v]) 
    {
        if (a[tree[v]]<=x) return tree[v];
        else return -1;
    }
    if (l<=q[v*2]) 
    {
        int t=find(v*2,l,r,x);
        if (t!=-1) return t;
    }
    if (r>=p[v*2+1]) return find(v*2+1,l,r,x);
}
main()
{
    int T,n;
    scanf("%d",&T);
    while (T-->0)
    {
        scanf("%d",&n);
        build(1,1,n);
        int q;
        scanf("%d",&q);
        for (int i=1;i<=q;i++)
        {
            int l,r,x;
            scanf("%d%d",&l,&r);
            x=a[l];
            while (l<r)
            {
                l++;
                l=find(1,l,r,x);
                if (l==-1) break;
                x%=a[l];
            }
            cout<<x<<endl;
        }
    }
}
