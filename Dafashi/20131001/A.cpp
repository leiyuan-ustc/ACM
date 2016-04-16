#include <iostream>
#include <cstdlib>
using namespace std;
struct pro
{
    int x,y;
}a[100010];
int b[100010];
int com(const void *e1,const void *e2)
{
    return ((pro *)e1)->x-((pro *)e2)->x;
}
int main()
{
    int t,n,tmp,ans;
    cin>>t;
    for (int p=1;p<=t;p++)
    {
        tmp=1e9+1;
        ans=2e9+1;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y;
        }
        qsort(a+1,n,sizeof(pro),com);
        b[n+1]=0;
        for (int i=n;i>=1;i--)
         b[i]=max(a[i].y,b[i+1]);
        for (int i=1;i<=n;i++)
          ans=min(ans,a[i].x+b[i+1]);
        cout<<"Case "<<p<<": "<<ans<<endl;
    }
    return 0;
}
