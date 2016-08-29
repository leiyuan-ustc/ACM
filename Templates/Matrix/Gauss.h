#include <cstdio>
const int MAXN=105;
#define LL long long
/*
高斯消元 - 同余方程
一般只要求求一个解/而且必然有解
*/
LL GCD(LL a, LL b)
{
	if(!b)
	{
		return a;
	}
	return GCD(b,a%b);
}
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
LL Mod(LL a,LL b,LL c)
{
	if(!b)
	{
		return 1%c;
	}
	return Mod(a*a%c,b/2,c)*((b&1)?a:1)%c;
}
class GaussMatrix
{
	public:
		int r,c;
		LL d[MAXN][MAXN];
		LL x[MAXN];        // 某个解集
		LL xcnt;          // 解集个数
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
		void swap_col(int ca,int cb)
		{
			for(int i=0;i<r;i++)
			{
				LL tmp=d[i][ca];
				d[i][ca]=d[i][cb];
				d[i][cb]=tmp;
			}
		}
		void getAns(LL mod)
		{
			for(int i=c-1;i>=0;i--)
			{
				LL tmp=d[i][c];
				// d[i][i] * x[i] + (d[i][i+1]*x[i+1] +  + d[i][c]*x[c]) = K*mod + tmp;
				for(int j=i+1;j<c;j++)
				{
					tmp=((tmp-d[i][j]*x[j])%mod+mod)%mod;
				}
				// d[i][i] * x[i] = K * mod + tmp;
				// d[i][i] * x[i] + (-K) * mod = tmp;
				// a * x[i] + b * (-K) = tmp;
				LL X,Y;
				ExpGcd(d[i][i],mod,X,Y);
				x[i]=((X%mod+mod)%mod)*tmp%mod;
			}
		}
		// -1 表示无解
		LL gauss(LL mod)
		{
			int i,j,k;
			int col,maxrow;
			// 枚举行，步进列
			for(i = 0,col=0;i<r && col<c;i++)
			{
				//debug_print();
				maxrow=i;
				// 找到i到r-1行中col元素最大的那个值
				for(j=i+1;j<r;j++)
				{
					if(abs(d[j][col])>abs(d[maxrow][col]))
					{
						maxrow=j;
					}
				}
				// 最大的行和第i行交换
				if(maxrow!=i)
				{
					swap_row(i,maxrow);
				}
				if(d[i][col]==0)
				{
					// 最大的那一行的当前col值 等于0，继续找下一列
					col++;
					i--;
					continue;
				}
				for(j=i+1;j<r;j++)
				{
					if(d[j][col])
					{
						// 当前行的第col列如果不为0，则进行消元
						// 以期第i行以下的第col列的所有元素都消为0
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
			// i表示从i往后的行的矩阵元素都为0
			// 存在 (0 0 0 0 0 0 d[j][c]) (d[j][c] != 0) 的情况，方程无解
			for(j=i;j<r;j++)
			{
				if(d[j][c])
				{
					return -1;
				}
			}
			// 自由变元数 为 (变量数 - 非零行的数目)
			int free_num=c-i;
			// 交换列，保证最后的矩阵为严格上三角，并且上三角以下的行都为0
			for(i=0;i<r && i<c;i++)
			{
				if(!d[i][i])
				{
					// 对角线为0
					for(j=i+1;j<c;j++)
					{
						// 在该行向后找第一个不为0的元素所在的列，交换i和这一列
						if(d[i][j]) break;
					}
					if(j<c)
					{
						swap_col(i,j);
					}
				}
			}
			xcnt = (((LL)1)<<(LL)free_num);
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
