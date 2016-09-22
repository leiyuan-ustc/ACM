#include <cstdio>
const int MAXN=105;
#define LL long long
/*
高斯消元 - 同余方程
一般只要求求一个解/而且必然有解
*/
LL ExpGcd(LL a,LL b,LL &X,LL &Y)
{
	LL q,temp;
	if(!b)
	{
		q=a;
		X=1;
		Y=0;
		return q;
	}
	else
	{
		q=ExpGcd(b,a%b,X,Y);
		temp=X;
		X=Y;
		Y=temp-(a/b)*Y;
		return q;
	}
}
struct GaussMatrix
{
		int r,c;
		LL d[MAXN][MAXN];
		LL x[MAXN]; // 某个解集
		LL xcnt;    // 解集个数
		LL abs(LL v)
		{
			return v<0?-v:v;
		}
		void swap_row(int ra,int rb)
		{
			for(int i=0;i<=c;i++)
			{
				LL tmp=d[ra][i];
				d[ra][i]=d[rb][i];
				d[rb][i]=tmp;
			}
		}
		void getAns(LL mod)
		{
			for(int i=c-1;i>=0;i--)
			{
				LL tmp=d[i][c];
				for(int j=i+1;j<c;j++)
				  tmp=((tmp-d[i][j]*x[j])%mod+mod)%mod;
				LL X,Y;
				ExpGcd(d[i][i],mod,X,Y);
				x[i]=((X%mod+mod)%mod)*tmp%mod;
			}
		}
		LL gauss(LL mod) // -1 表示无解
		{
			int i,j,k;
			int col,maxrow;
			for(i=0,col=0;i<r && col<c;i++)
			{
				maxrow=i;
				for(j=i+1;j<r;j++)
				  if(abs(d[j][col])>abs(d[maxrow][col])) maxrow=j;
				if(maxrow!=i) swap_row(i,maxrow);
				if(d[i][col]==0)
				{
					col++;
					i--;
					continue;
				}
				for(j=i+1;j<r;j++)
				{
					if(d[j][col])
					{
						LL lastcoff=d[i][col];
						LL nowcoff=d[j][col];
						for(k=col;k<=c;k++)
						{
							d[j][k]=(d[j][k]*lastcoff-d[i][k]*nowcoff)%mod;
							if (d[j][k]<0) d[j][k]+=mod;
						}
					}
				}
				col++;
			}
			for(j=i;j<r;j++)
				if(d[j][c])	return -1;
			int free_num=c-i;
			xcnt=(((LL)1)<<(LL)free_num);
			getAns(mod);
			return xcnt;
		}
		void debug_print()
		{
			int i,j;
			printf("-------------------------------\n");
			for(i=0;i<r;i++)
			{
				for(j=0;j<=c;j++)
				{
					printf("%d ",d[i][j]);
				}
				puts("");
			}
			printf("-------------------------------\n");
		}
};
