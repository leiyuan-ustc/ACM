#include <iostream>
using namespace std;
int a[50010];
long long m,n;
long long findans(long long k);
long long work();
int main()
{
    long long t,ans;
    cin>>t;
    while (t-->0)
    {
        cin>>n>>m;
        ans=work();
        cout<<ans<<endl;
    }
}
long long findans(long long k)
{
    long long p=0;
    for (int j=1;j<=n;j++)
    {
        int l=1,r=n;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            long long t,tt;
			t=mid;
            t*=mid;
            tt=100000;
            tt*=mid;
            t+=tt;
            tt=j;
            tt*=j;
			t+=tt;
			tt=100000;
			tt*=j;
			t-=tt;
			tt=mid;
			tt*=j;
			t+=tt;
            if (t<k) l=mid+1;
            else r=mid-1;
        }
        a[j]=r;
        p+=r;
    }
    return p;
}
long long work()
{
    long long l,r,mid,i,j,min1=1e18,t,tt;
    l=-100000*n;
    r=3*n*n+100000*n;
    while (l<r)
    {
        mid=(l+r)>>1;
        long long p=findans(mid);
        if (p<m-1) l=mid+1;
        else if (p>m-1) r=mid-1;
        else
        {
            for (j=1; j<=n; j++)
            {
                t=(a[j]+1);
                t*=(a[j]+1);
                tt=100000;
                tt*=(a[j]+1);
				t+=tt;
				tt=j;
				tt*=j;
				t+=tt;
				tt=100000;
				tt*=j;
				t-=tt;
				tt=(a[j]+1);
				tt*=j;
				t+=tt;
                if (a[j]+1<=n && min1>t) min1=t;
            }
            return min1;
        }
    }
}
