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
#include <unordered_map>
#include <set>
#include <iterator>


using namespace std;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, l, r) for(int (i) = (l); (i) <= (r); i++)
const int N = 1e6, M = 1e4;

unordered_map<int, int> mp;
int dp[2][N], cnt[2][N];
int fac[M], inv[M * M], MO, mod, phi, n;
int prefix[N];
int p[N], vis[N], tot;

void prime() {
  tot = 1;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) p[tot++] = i;
    for (int j = 1; j < tot && i * p[j] < N; j++) {
      vis[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}

int pmod(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % mod;
    b >>= 1;
    a = 1LL * a * a % mod;
  }
  return ans;
}

void init(int tot) {
  fac[0] = 1;
  REPP(i, 1, MO - 1) {
    fac[i] = 1LL * i * fac[i - 1] % mod;
  }
  inv[0] = 0, inv[1] = 1;
  REPP(i, 2, mod - 1) {
    if (i % MO == 0) {
      inv[i] = 0;
      continue;
    }
    inv[i] = mod - 1LL * mod / i * inv[mod % i] % mod;
  }
  prefix[0] = 1;
  REPP(i, 1, tot) {
    if (p[i] == MO) {
      prefix[i] = prefix[i - 1];
    }
    else {
      prefix[i] = 1LL * prefix[i - 1] * p[i] % mod;
    }
  }
}

int calc(int x) {
  if (x == 0) return 1;
  int k = x / MO, b = x % MO;
  int res = calc(k);
  int p = pmod(fac[MO - 1], k);
  p = 1LL * p * fac[b] % mod;
  p = 1LL * p * res % mod;
  return p;
}

int DIV(int a, int b) {
  return 1LL * a * inv[b] % mod;
}

int main() {
  prime();
  int t, ca = 1;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &MO);
    mod = MO * MO, phi = MO * (MO - 1);
    if (n < MO) {
      int ans = 1;
      REPP(i, 1, tot) {
        if (p[i] > n) break;
        ans = 1LL * ans * p[i] % mod;
      }
      printf("Case #%d: %d\n", ca++, ans / MO % MO);
      continue;
    }
    int rt = int(sqrt(n + 0.5));
    int tot = upper_bound(p + 1, p + ::tot, rt) - p - 1;
    init(tot);
    mp.clear();
    vector<int> tmp;
    int now = 0;
    for (int i = 1; i <= n; i++) {
      int k = n / i;
      tmp.push_back(k);
      dp[0][now] = calc(k);
      cnt[0][now] = k;
      mp[k] = now++;
      i = n / k;
    }
    int cur = 0;
    REPP(i, 1, tot) {
      REP(j, now) {
        int k = tmp[j];
        if (p[i] * p[i] > k) {
          dp[cur ^ 1][j] = dp[cur][j];
          cnt[cur ^ 1][j] = cnt[cur][j];
          continue;
        }
        int id = mp[k / p[i]];
        dp[cur ^ 1][j] = DIV(dp[cur][j], DIV(dp[cur][id], prefix[i - 1]));
        int &ans = dp[cur ^ 1][j];
        if (p[i] != MO) {
          int cc = pmod(p[i], cnt[cur][id] - i) % mod;
          ans = DIV(ans, cc);
        }
        cnt[cur ^ 1][j] = cnt[cur][j] - (cnt[cur][id] - i);
      }
      cur ^= 1;
    }
    printf("Case #%d: %d\n", ca++, dp[cur][mp[n]] % MO);
  }
  return 0;
}

