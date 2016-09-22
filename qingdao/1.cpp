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
std::vector<long long> v;
int N;
int T;
//============================



int main(){

	FOR0(i1, 31)FOR0(i2, 20)FOR0(i3, 16)FOR0(i4, 12) {
		long long ans = 1;
		bool ok = 1;
		FOR0(j1, i1) {
			ans *= 2;
			if (ans > 1.5e9) {
				ok = 0;
				break;
			}
		}
		if (ok)FOR0(j2, i2) {
			ans *= 3;
			if (ans > 1.5e9) {
				ok = 0;
				break;
			}
		}
		if (ok)FOR0(j3, i3) {
			ans *= 5;
			if (ans > 1.5e9) {
				ok = 0;
				break;
			}
		}
		if (ok)FOR0(j4, i4) {
			ans *= 7;
			if (ans > 1.5e9) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			v.push_back(ans);
			N++;
		}
	}
	//cout << N << endl;
	sort(v.begin(), v.end());
	int T;
	scanf("%d", &T);
	FOR0(i, T) {
		int tt;
		scanf("%d", &tt);
		long long ans = *(lower_bound(v.begin(), v.end(), tt));
		printf("%d\n", ans);
	}
    return 0;
}