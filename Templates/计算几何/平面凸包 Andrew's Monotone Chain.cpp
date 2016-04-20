#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct Point
{
    int x, y;
    int num;
    Point(int x = 0, int y = 0): x(x), y(y) {}
} a[50100];
typedef Point Vector;
Vector operator - (Point A, Point B)
{
    return Vector(A.x - B.x, A.y - B.y);
}
int Cross(Vector A, Vector B)
{
    return A.x * B.y - A.y * B.x;
}
int Length(Vector A)
{
    return (A.x * A.x + A.y * A.y);
}
int n;
int cmp(const Point A, const Point B)
{
    if (A.x!=B.x) return A.x<B.x;
    return A.y<B.y;
}

void work()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    if (n==1)
    {
        cout<<"NO"<<endl;
        return ;
    }
    sort(a+1,a+n+1,cmp);
    
    
    int U[50100],L[50100];//分别为上凸包、下凸包，如果所有点在一条线上则上下凸包相同，会被计算两次
    int u,l;
    
    L[1]=1;
    l=1;
    for (int i=2;i<=n;i++)
    {
        while (l>1 && Cross(a[L[l]]-a[L[l-1]],a[i]-a[L[l]])<0)
            l--;
        l++;
        L[l]=i;
    }
    
    U[1]=n;
    u=1;
    for (int i=n-1;i>=1;i--)
    {
        while (u>1 && Cross(a[U[u]]-a[U[u-1]],a[i]-a[U[u]])<0)
            u--;
        u++;
        U[u]=i;
    }
    
    Vector q[50100];
    int tot;
    for (int i=1;i<=l;i++)
        q[i]=a[L[i]];
    for (int i=2;i<=u;i++)
        q[i+l-1]=a[U[i]];
    
    tot=l+u-1;
}