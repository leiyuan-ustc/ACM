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
double ans[1000000];
int N;
int T;
//============================



int main(){
	double a = 0;
	FOR1(i, 999999) {
		a += double (1) / double ((long long)i * i);
		ans[i] = a;
	}
	long long b;
	char t[2000000];
	while (scanf("%s", t) != EOF) {
		//cout << strlen(t) << endl;
		
		if(t[0] != 0 && t[1] != 0
			 && t[2] != 0  && t[3] != 0
			  && t[4] != 0  && t[5] != 0
		) b = 999999;
		else sscanf(t, "%lld", &b);
		printf("%.5lf\n", ans[b]);
	}
    return 0;
}