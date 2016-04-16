#include <iostream>
#include <algorithm>
using namespace std;
int f[2][100010],a[100010],b[2010],m,n;
const int INF=1e9+100000;
int main()
{
    int t,l,r,pr,pl;
    cin>>m>>n;
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int j=0;j<=m;j++)
    {
        f[0][j]=0;
        f[1][j]=INF;
    }
    sort(a+1,a+1+m);
    sort(b+1,b+1+n);
    pl=1;pr=m;
    for (int i=1;i<=n;i++)
    {
        t=upper_bound(a+1,a+m+1,b[i])-a;
        l=max(i,t-n/2-2);
        r=min(m,t+n/2+2);
        //cout<<l<<" "<<r<<endl;
        f[i%2][l-1]=INF;
        //cout<<f[i][i]<<" ";
        for (int j=l;j<=r;j++)
        {
            if (j<=pr+1) f[i%2][j]=min(f[(i-1)%2][j-1]+abs(b[i]-a[j]),f[i%2][j-1]);
            else f[i%2][j]=min(f[(i-1)%2][pr]+abs(b[i]-a[j]),f[i%2][j-1]);
            //cout<<f[i][j]<<" ";
        }
        pl=l;pr=r;
        //cout<<endl;
    }
    cout<<f[n%2][r]<<endl;
}
