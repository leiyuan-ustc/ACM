#include <iostream>
#include <algorithm>
using namespace std;
int T,n,m,l,r,a[500010],ans,b[500010];
long long k;
bool check(int l,int r,int m,long long k)
{
	int len=r-l+1;
	long long t=0;
	for (int i=l;i<=r;i++)
	{
		b[i-l+1]=a[i];
	}
	sort(b+1,b+len+1);
	for (int i=1;i<=len>>1&&i<=m;i++)
	{
		t+=(long long)(b[i]-b[len-i+1])*(b[i]-b[len-i+1]);
	}
	if (t>k) return false;
	else return true;
}
void RD(int &x) {
    static char c;
    for (c = getchar() ; !isdigit(c) ; c = getchar());
    x = c - '0';
    for (c = getchar() ; isdigit(c) ; c = getchar())
        x = x * 10 + c - '0';
}
main()
{
	scanf("%d",&T);
	while (T-->0)
	{
		scanf("%d%d%lld",&n,&m,&k);
		ans=0;
		for (int i=1;i<=n;i++) RD(a[i]);
		l=1;
		while (l<=n)
		{
			int t=1;
			r=l;
			while (r<=n&&check(l,r,m,k))
			{
				t<<=1;
				r=l+t-1;
			}
			//l+t/2-1 ok,r not ok?
			//!!注意，上述r未必不行，故需再判断下缩小范围，否则范围太大造成超时 
			int q=min(r,n);
			int p;
			if (check(l,q,m,k)) p=q;
			else p=l+(t>>1)-1;
			while (p<=q)
			{
				int mid=(p+q)>>1;
				if (check(l,mid,m,k)) p=mid+1;
				else q=mid-1;
			}
			//q
			l=q+1;
			ans++;
		}
		printf("%d\n",ans);
	}		
}
