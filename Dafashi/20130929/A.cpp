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
#define lowbit(x) (x)&(-x)
#define MEMSET(x, y) memset((x), (y), sizeof(x))

using namespace std;
//============================
struct money {
	int d, n;
	bool operator < (const money & A) const {
		return d < A.d;
	}
} m[25];
int N, C, ans;
//============================



int main(){
	cin >> N >> C;
	FOR0(i, N) {
		cin >> m[i].d >> m[i].n;
		if (m[i].d >= C) {
			ans += m[i].n;
			N--, i--;
		}
	}
	sort(m, m + N);
	//cout << m[0].d << endl;
	do {
		bool ok = 0;
		int now = C;
		for (int i = N - 1; i >= 0; i--) {
			int need = now / m[i].d;
			need = min(need, m[i].n);
			m[i].n -= need;
			now -= m[i].d * need;
			if (!now) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			ans ++;
		}
		else {
			for (int j = 0; j < N; j++) {
				if (m[j].d >= now && m[j].n) {
					m[j].n--;
					ans ++;
					ok = 1;
					break;
				}
			}
			if (!ok) {
				break;
			}
		}
	}while (1);
	cout << ans << endl;
    return 0;
}