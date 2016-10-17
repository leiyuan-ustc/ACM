#include <cstdio>
#include <cmath>
#include <algorithm>
#define swap(a,b) std::swap(a,b)
#define INF 100000000000000000ll
#define ll long long
namespace FFT {
	typedef double lf;
	const lf pi=acos(-1);
	const int N=200005;
	int rev[N];
	struct icp {
		lf r, i;
		icp(const lf &_r=0, const lf &_i=0) : r(_r), i(_i) {}
	};
	icp operator + (const icp &a, const icp &b) {
		return icp(a.r+b.r, a.i+b.i);
	}
	icp operator - (const icp &a, const icp &b) {
		return icp(a.r-b.r, a.i-b.i);
	}
	icp operator * (const icp &a, const icp &b) {
		return icp(a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r);
	}
	inline int getlen(const int &n) {
		int len=1, bl=-1;
		for(; len<n; len<<=1, ++bl);
		for(int i=0; i<len; rev[i]=(rev[i>>1]>>1)|((i&1)<<bl), ++i);
		return len;
	}
	void fft(icp *a, const int &n, const int &f) {
		for(int i=0; i<n; ++i) {
			if(rev[i]<i) {
				swap(a[rev[i]], a[i]);
			}
		}
		for(int m=2; m<=n; m<<=1) {
			icp wn(cos(pi*2/m), sin(pi*2/m)*f);
			for(int i=0, mid=m>>1; i<n; i+=m) {
				icp w(1);
				for(int j=0; j<mid; ++j) {
					icp u=a[i+j], v=a[i+j+mid]*w;
					a[i+j]=u+v;
					a[i+j+mid]=u-v;
					w=w*wn;
				}
			}
		}
		if(f==-1) {
			for(int i=0; i<n; ++i) {
				a[i].r/=n;
			}
		}
	}
}
using namespace FFT;

inline int RD()
{
	int res,sign=1;
	char cr;
	while( (cr=getchar())<'0' || cr>'9')
		if(cr=='-') break;
	if(cr=='-') sign=-1,res=0;
	else res=cr-'0';
	while( (cr=getchar())>='0' && cr<='9')
		res=res*10+cr-'0';
	return res;
}
void calc(icp* a,icp* b,int n)
{
	int len=FFT::getlen(n<<1);
	FFT::fft(a,len,1);
	FFT::fft(b,len,1);
	for(int i=0;i<len;i++)
		a[i]=a[i]*b[i];
	FFT::fft(a,len,-1);
}
icp p1[200005],p2[200005];
ll ra[200005],rb[200005];
int main()
{
	int T=RD();
	while(T--)
	{
		int n=RD();
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			p1[i].r=ra[i]=RD();
			p1[i].i=0;
			ans+=(ll)ra[i]*ra[i];
		}
		for(int i=n-1;i>=0;i--)
		{
			p2[i].r=rb[i]=RD();
			p2[i].i=0;
			ans+=(ll)rb[i]*rb[i];
		}
		calc(p1,p2,n);
		int mx=-INF,pos=0;
		for(int i=0;i<n;i++)
		{
			ll res=(long long)(p1[i].r+p1[i+n].r);
			if(res>mx)
				mx=res,pos=i;
		}
		int ptr1=0,ptr2=pos;
		for(int i=0;i<n;i++)
		{
			ans-=ra[ptr1]*rb[ptr2]*2;
			if(++ptr1>=n) ptr1-=n;
			if(--ptr2<0) ptr2+=n;
		}
		printf("%I64d\n",ans);
		for(int i=FFT::getlen(n<<1)+5;i>=0;i--)
			p1[i].r=p1[i].i=p2[i].r=p2[i].i=0;
	}
}
