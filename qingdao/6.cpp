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
const int MAXN = 500000;
int deg[MAXN];
int N, M;
int v[MAXN];
//int ans;
int fa[MAXN];
//============================

int find(int x) {
	return fa[x] = (fa[x] == x) ? x : find(fa[x]);
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(deg, 0, sizeof(deg));
		int ans = 0;
		scanf("%d%d", &N, &M);
		FOR1(i, N)  {
			scanf("%d", &v[i]);
			fa[i] = i;
		}
		FOR1(i, M) {
			int a, b;
			scanf("%d%d", &a, &b);
			deg[a]++, deg[b]++;
			a = find(a), b = find(b);
			fa[b] = a;
		}

		int ffa = find(1);
		bool ok = true;
		FOR(i, 1, N) {
			//cout << i << ": " << find(i) << endl;
			if (find(i) != ffa) {
				printf("Impossible\n");
				ok = false;
				break;
			}
		}
		if (!ok) continue;

		int c = 0;
		int a, b;
		FOR1(i, N) {
			if (deg[i] & 1) {
				//deg[i]++;
				//deg[i] /= 2;
				if ((deg[i] + 1) & 2) {
					ans ^= v[i];
				}
				c ++;
				//cout << "!" << i << endl;
				if (c == 3) {
					ok = false;
					break;
				}

			}
			else {
				//deg[i] /= 2;
				if ((deg[i] + 1) & 2) {
					ans ^= v[i];
				}
			}
		}
		if (!ok) {
			printf("Impossible\n");
		}
		else {
			//cout << ans << endl;
			int tans = -100000000;
			if (!c) {
				FOR1(i, N) {
					tans = max(tans, ans ^ v[i]);
				}
				ans = tans;
			}
			printf("%d\n", ans);
		}
	}
	
	//int tans = ans;

	
    return 0;
}