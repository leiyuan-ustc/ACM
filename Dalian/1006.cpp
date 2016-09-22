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

int M, N;
//============================



int main(){
	while (scanf("%d", &M) != EOF) {
		FOR0(kkk, M) {
			scanf("%d", &N);
			int even = 0, odd = 0, sum = 0;
			bool ok = 1;
			FOR0(i, N) {
				int t;
				scanf("%d", &t);
				if (t < 0 || t > 2 * (N - 1)) {
					ok = 0;
					//break;
				}
				if (t & 1) odd++;
				else even++;
				sum += t;
			}
			if (!ok) {
				printf("F\n");
			}
			else {
				if (sum == N * (N - 1)) {
					printf("T\n");
				}
				else {
					printf("F\n");
				}
			}
		}
	}
    return 0;
}