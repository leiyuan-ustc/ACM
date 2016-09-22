//
//  Created by 赵宏祝 .
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <iterator>

#define FOR0(i, n) for(int (i) = 0; (i) < (n); i++)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); i++)
#define FOR(i, l, r) for(int (i) = (l); (i) <= (r); i++)
#define MEMSET(x, y) memset((x), (y), sizeof((x)))
#define lowbit(x) (x)&(-x)

using namespace std;
//============================
typedef long long LL;
int T;
long long M, N, K;
const int MOD = 1e9 + 7;
long long powermod[1111116];
//============================

LL quick_mod(LL a, LL b, int p)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

LL C(LL n, LL m, int p)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ans = ans * (a * quick_mod(b, p-2, p) % p) % p;
    }
    return ans;
}
/*
LL Lucas(LL n, LL m, int p)
{
	if(n < 0) return 0;
    if(m == 0 || n == m) return 1;
    if (n < m) return 0;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
*/
LL Lucas(LL n, LL m, int p) {
	if(n < 0) return 0;
    if(m == 0 || n == m) return 1;
    if (n < m) return 0;
	LL ans = powermod[n];
	LL t = quick_mod(powermod[m], p - 2, p);
	LL t2 = quick_mod(powermod[n - m], p - 2, p);
	ans *= t; ans %= p;
	ans *= t2; ans %= p;
	return ans;
}

void exgcd(LL a, LL b, LL &d, LL &x, LL &y) {
    if (!b) {
        d = a, x = 1, y = 0;
    }
    else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}



int main()
{
	ios::sync_with_stdio(false);
    cin >> T;
    powermod[0] = 1;
    FOR1(i, 1111111) {
    	powermod[i] = (long long)i * powermod[i - 1] % MOD;
    }
    while (T--) {
        cin >> N >> M >> K;
    	//N = 500000, M = 5000, K = 55;
        long long ans = Lucas(N - (M - 1) * K, M, MOD);

        //cout << ans << endl;

        for(int i = 0; i < min(K, N - (M - 1) * K - (M - 2)); i++) {
            LL t = Lucas(N - i - 2 - (M - 1) * K, M - 2, MOD);
            t *= i + 1;
            t %= MOD;
            //cout << t << endl;
            ans -= t;
            ans += MOD;
            ans %= MOD;
        }

        cout << ans << endl;

    }
    return 0;
}

        /*
        long long t = (LL)K * (M - 1) * (M - 1);
        t %= MOD;
        t *= K; t %= MOD;
        long long t2 = (LL)K*(M - 1)*(2 * N + 3);
        t2 %= MOD;
        t -= t2; t += 2 * MOD; t %= MOD;
        t2 = N * N + 3 * N + 2;
        t2 %= MOD;
        t += t2; t %= MOD;
        t2 = Lucas(N + (1 - M) * K, M - 2, MOD);
        t *= t2; t %= MOD;
        long long t3 = Lucas(N - K * M, M - 2, MOD);
        t2 = (LL)(N + 2)*(K * M - N - 1);
        t2 %= MOD; t2 *= t3; t2 %= MOD;
        t += t2; t %= MOD;

        t3 = quick_mod(M - 1, MOD - 2, MOD);
        t2 = quick_mod(M, MOD - 2, MOD);
        t *= t2; t %= MOD;
        t *= t3; t %= MOD;

        ans -= t;
        ans += 2 * MOD;
        ans %= MOD;
    */
