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

#define FOR0(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define FOR(i, l, r) for(int (i) = (l); (i) <= (r); (i)++)
#define lowbit(x) (x)&(-x)
#define MEMSET(x, y) memset((x), (y), sizeof(x))

using namespace std;
//============================

int T;
int k[400], v[400];
long long dp[400][400];
int N;
//============================



int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long f(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = -2;
	if (l == r - 1) {
		
	}
}

int main(){
	cin >> T;
	while (T--) {
		cin >> N;
		FOR1(i, N) {
			cin >> k[i];
		}
		FOR1(i, N) {
			cin >> v[i];
		}

		memset(dp, -1, sizeof(dp));
		
	}
    return 0;
}
/*
		//cout << dp[0][0];
		dp[0][0] = 0, dp[0][1] = 0;
		dp[1][0] = 0, dp[1][1] = -1e18;
		FOR(i, 2, N) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = gcd(k[i], k[i - 1]) == 1 ? -1e18 : 
				(dp[i - 1][0] + v[i] + v[i - 1]);
		}
		cout << max(dp[N][0], dp[N][1]) << endl;
		*/