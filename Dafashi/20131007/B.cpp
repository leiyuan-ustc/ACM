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
int N;
int T;
struct ts {
	int len, ori;
	bool operator < (const ts &a) const {
		return a.len > len;
	}
} s[1005];
int stamp[1005];
int ans[1005][1005];
//============================

bool plusone(int *a, int len) {
	int i;
	for (i = len - 1; i >= 0; i--) {
		if (!a[i]) {
			a[i] = 1;
			return true;
		}
		else {
			a[i] = 0;
		}
	}
	return false;
}

int main(){
	cin >> N;
	FOR0(i, N) {
		cin >> s[i].len;
		s[i].ori = i;
	}
	sort(s, s + N);
	//cout << s[0].len;
	FOR0(i, N) {
		stamp[s[i].ori] = i;
	}
	int now, last = s[0].len;
	int nowans[1005] = {0};
	bool ok = 1;
	FOR1(i, N - 1) {
		now = s[i].len;
		if (now != last) {
			if (!plusone(nowans, last)) {
				ok = 0;
				break;
			}
			last = now;
		}
		else {
			if (!plusone(nowans, now)) {
				ok = 0;
				break;
			}
		}
		memcpy(ans[i], nowans, sizeof(nowans));
	}
	if (ok) {
		printf("YES\n");
		FOR0(i, N) {
			int t = stamp[i];
			FOR0(j, s[t].len) {
				printf("%d", ans[t][j]);
			}
			printf("\n");
		}
	}
	else {
		printf("NO\n");
	}
    return 0;
}