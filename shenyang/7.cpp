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
long long f[20][2][2];
int N;
//int singleans[10] = {0, 1, }
//============================

int getnum(long long a, int k) {
	long long ans = 1;
	FOR0(i, k) ans *= 10;
	return (a / ans) % 10;
}

long long dp(int l, int eoro, int ok) {

	if (f[l][eoro][ok] != -1) return f[l][eoro][ok];
	if (l == 0) {
		if (eoro == ok)
			return f[l][eoro][ok] = 5;
		else return f[l][eoro][ok] = 0;
	}
	long long ans = 0;
	if (eoro == 0 & ok == 1) {
		ans = dp(l - 1, 0, 0);
	}
	if (eoro == 0 & ok == 0) {
		ans = dp(l - 1, 0, 1) + dp(l - 1, 1, 1);
	}
	if (eoro == 1 & ok == 0) {
		ans = dp(l - 1, 1, 1);
	}
	if (eoro == 1 & ok == 1) {
		ans = dp(l - 1, 1, 0) + dp(l - 1, 0, 1);
	}
	ans *= 5;
	cout << "f[" << l << "][" << eoro << "][" << ok << "] = " << ans << endl;
	return f[l][eoro][ok] = ans;
}

long long getans(long long a) {

	if (a < 10) {
		cout << "ans for "  << a << " " << a / 2 << endl;
		return a / 2;
	}
	long long ans = 0;
	for (int k = 18; k >= 0; k--) {
		int t;
		if ((t = getnum(a, k)) != 0) {
			long long tt = 1;
			FOR0(i, k) tt *= 10;
			cout << "tt for "  << a << " " << tt << endl;
			t--;
			ans += ((t + 1) / 2) * (dp(k - 1, 1, 0) + dp(k - 1, 0, 1));
			ans += t / 2 * dp(k - 1, 0, 0);
			ans += getans(tt - 1);
			//if ((tt & 1) == 0) ans++;
			break;
		}
	}
	cout << "ans for "  << a << " " << ans << endl;
	return ans;
}

int main(){
	cin >> T;
	int tt = 0;
	while (T--) {
		tt++;
		memset(f, -1, sizeof(f));
		long long a, b;
		cin >> a >> b;
		cout << "Case #" << tt << ": " <<  getans(b) - getans(a - 1) << endl;
	}
    return 0;
}