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

//============================

int main(){
	long long L, R;
	while (scanf("%lld%lld", &L, &R) != EOF) {
		long long ans = 0;
		if (R <= 1) ans = 0;
		else if (L == 0) {
			ans = (R + 1) / 2;
		}
		else if (L == 1) {
			ans = (R + 1) / 2;
		}
		else if (L == 2) {
			if (R == 2) ans = 2;
			else ans = (R - L) / 2 + 1;
		}
		else if (R - L < 3) {
			ans = 2;
		}
		else {
			ans = (R - L + 2) / 2;
		}
		printf("%lld\n", ans);
	}
	
	

	
    return 0;
}
