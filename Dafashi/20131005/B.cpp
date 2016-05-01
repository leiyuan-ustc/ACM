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

int T;
int N, M;
int s[50010];
double ansmin, ansmax;
//============================



int main(){
	while (scanf("%d%d", &N, &M) != EOF) {
		if (N == 0) return 0;
		ansmin = ansmax = 0;
		FOR1(i, N) {
			scanf("%d", &s[i]);
		}
		double tmp = (double)M / N;
		for (int i = 1; i <= N - M + 1; i++) {
			ansmin += s[i] * tmp;
			tmp /= N - i;
			tmp *= N - i - M + 1;
		}
		tmp = (double)M / N;
		for (int i = 1; i <= N - M + 1; i++) {
			ansmax += s[N - i + 1] * tmp;
			tmp /= N - i;
			tmp *= N - i - M + 1;
		}
		printf("%.3f\n", ansmax - ansmin);

	}
    return 0;
}