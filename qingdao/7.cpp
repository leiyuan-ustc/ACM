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
const int MAXN = 110000;
int deg[MAXN];
int N, M;
int v[MAXN];
long long T;
//============================


bool check(int mid);
int main(){
	int TT;
	scanf("%d", &TT);
	while (TT--) {
		//scanf("%d%lld", &N, &T);
		N=100000; T=100000000;
		FOR0(i, N) {
			//scanf("%d", &v[i]);
			v[i]=i;
		}
		//sort(v, v + N);
		int l = 1, r = N;
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (!check(mid)) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		if (check(l)) r = l;
		printf("%d\n", r);
	}
	
	

	
    return 0;
}
bool check(int mid)
{
	long long ans=0;
	priority_queue<long long> Q;
	FOR0(i,N) Q.push(-v[i]);
	while (Q.size() > 1)
	{
		long long t=0;
		for (int i=0;i<mid && !Q.empty();i++)
		{
			t+= -Q.top();
			//cout << -Q.top() << " " << i << endl;
			Q.pop();
		}
		ans+=t;
		Q.push(-t);
		if (ans > T) return false;
	}
	return ans <= T;
}