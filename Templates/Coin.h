//求硬币可以凑出多少种总额
#include <algorithm>
#include <iostream>
using namespace std;
long long dp[6000000 + 16]; // dp[i][j] := 用前i种硬币凑成j时第i种硬币最多能剩余多少个
long long A[1000],C[1000];//面值和个数
long long work(long long n,long long m)//n为硬币种类数，输出在m以内可被凑出多少种总额
{
    for (long long i=1;i<=m;i++) dp[i]=-1;
		dp[0] = 0;
		for (long long i = 0; i < n; ++i)
		{
			for (long long j = 0; j <= m; ++j)
			{
				if (dp[j] >= 0)
				{
					dp[j] = C[i];
				}
				else if (j < A[i]						// 用一个就超出，不能用
						|| dp[j - A[i]] <= 0)		// 连凑比j小的数的时候都用完了，此时更加用完了
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j - A[i]] - 1;		// 用上了一个第i个硬币
				}
			}
		}
		long long ans = count_if(dp + 1, dp + 1 + m , bind2nd(greater_equal<long long>(), 0)); // 总额0不算在答案内
        //ans++; //总额0算在内
        return ans;
}
