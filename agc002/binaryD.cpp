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
const int maxn = 7;
int T;
int N, M, Q;
int l[maxn], r[maxn];
int A[maxn], B[maxn], Z[maxn];
struct pack {
    int L, R;
    queue<int> q;
};
int ans[maxn];
int fa[maxn], size[maxn];
int nowe;
//============================

void dsuini() {
    FOR1(i, N) {
        fa[i] = i, size[i] = 1;
    }
}

int find(int x) {
    return fa[x] = (x == fa[x]) ? x : find(fa[x]);
}

void combine(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        fa[x] = y;
        size[y] += size[x];
    }
}

int main(){
    scanf("%d%d", &N, &M);
    FOR0(i, M) {
        scanf("%d%d", &l[i], &r[i]);
    }
    scanf("%d", &Q);
    FOR0(i, Q) {
        scanf("%d%d%d", &A[i], &B[i], &Z[i]);
    }
    dsuini();
    pack ini;
    ini.L = 0, ini.R = M;
    FOR0(i, Q) {
        ini.q.push(i);
    }
    queue<pack> que;
    que.push(ini);
    while (!que.empty()) {
        pack now = que.front();
        que.pop();
        if (now.L < now.R - 1) {
            int mid = (now.L + now.R) >> 1;
            if (nowe > mid) {
                dsuini();
                nowe = 0;
            }
            FOR(i, nowe, mid - 1) {
                combine(l[i], r[i]);
            }
            nowe = mid;
            pack t1, t2;
            t1.L = now.L, t1.R = mid;
            t2.L = mid, t2.R = now.R;
            while(!now.q.empty()) {
                int query = now.q.front();
                now.q.pop();
                int vers;
                int x = find(A[query]), y = find(B[query]);
                if (x == y) vers = size[x];
                else vers = size[x] + size[y];
                if (vers < Z[query]) {
                    t2.q.push(query);
                }
                else {
                    t1.q.push(query);
                }
            }
            if (!t1.q.empty()) {
                que.push(t1);
            }
            if (!t2.q.empty()) {
                que.push(t2);
            }
        }
        else {
            while(!now.q.empty()) {
                int query = now.q.front();
                now.q.pop();
                ans[query] = now.R;
            }
        }
    }
    FOR0(i, Q) {
        printf("%d\n", ans[i]);
    }
    return 0;
}