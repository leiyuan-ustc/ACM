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
#define MEMSET(x, y) memset((x), (y), sizeof((x)))
#define lowbit(x) (x)&(-x)

using namespace std;
//============================
const int MAX_SIZE = 26, maxnode = 300000, maxn = 200;
char s[maxn][100];
int counts[maxn], maxa = 0;

struct Trie {
    int ch[maxnode][MAX_SIZE];
    int val[maxnode];
    int nowsize;
    void ini() {
        nowsize = 0;
        MEMSET(val, 0);
        MEMSET(ch, 0);
    }
    int idx(char &t) {
        return t - 'a';
    }
    void add(char *a, int num) {
        int sz = strlen(a);
        int now = 0;
        int p;
        FOR0(i, sz) {
            p = idx(a[i]);
            if (!ch[now][p]) {
                ch[now][p] = ++nowsize;
            }
            now = ch[now][p];
        }
        val[now] = num;
    }
};

struct AhoCorasickAutomata {
    Trie s;
    int Lost[maxnode], last[maxnode];
    void getFail() {
        queue<int> Q;
        Lost[0] = 0;
        FOR0(i, MAX_SIZE) {
            int u = s.ch[0][i];
            if (u) {
                Q.push(u);
                Lost[u] = 0;
                last[u] = 0;
            }
        }
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            FOR0(i, MAX_SIZE) {
                int u;
                if ((u = s.ch[now][i])) {
                    Q.push(u);
                }
                else continue;
                int t = Lost[now];
                while (t && !s.ch[t][i]) {
                    t = Lost[t];
                }
                Lost[u] = s.ch[t][i];
                last[u] = s.val[Lost[u]] ? Lost[u] : last[Lost[u]];
            }
            
        }
    }
    void print(int p) {
        counts[s.val[p]]++;
        //printf("!%s\n", ::s[s.val[p]]);
        maxa = max(maxa, counts[s.val[p]]);
        if (last[p]) print(last[p]);
    }
    void find(char *T) {
        int len = strlen(T);
        int pos = 0;
        FOR0(i, len) {
            int c = s.idx(T[i]);
            while (pos && !s.ch[pos][c]) {
                pos = Lost[pos];
            }
            pos = s.ch[pos][c];
            if (s.val[pos]) {
                print(pos);
            }
            else if (last[pos]) print(last[pos]);
        }
    }
} ac;

//============================

int main(){
    
    return 0;
}