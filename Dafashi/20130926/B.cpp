#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=200200;
int n;
int a[MAXN],b[MAXN],c[MAXN];
long long d[MAXN];
long long ans;

void calc(int x[],int y[])
{
    for (int i=1;i<=n;i++)
        d[i]=x[i]-y[i];
    sort(d+1,d+n+1);
    for (int i=1;i<=n;i++)
    {
        ans+=(i-1)*d[i];
        ans+=-(n-i)*d[i];
    }
}

int main()
{
    while (1)
    {
        cin>>n;
        ans=0;
        if (n==0) break;
        for (int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        calc(a,b);
        calc(a,c);
        calc(b,c);
        cout<<ans/2<<endl;
    }
}