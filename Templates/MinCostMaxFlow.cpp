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
#define lowbit(x) (x)&(-x)，0

using namespace std;
//============================
const int INF = (int)1e9 + 9;
const long long INFLL = 1LL << 60;
const int maxn = 10010;

struct Edge
{
	int from, to, cap, flow;
	long long cost;
};

struct MCMF
{
	int n, m, s, t, flow;
	vector<Edge> edges;
	vector<int> G[maxn];
	long long d[maxn];
	int p[maxn], a[maxn];
	bool vis[maxn], inq[maxn];

	void addEdge(int from, int to, int cap, long long cost) {
		edges.push_back((Edge){from, to, cap, 0, cost});
		edges.push_back((Edge){to, from, 0, 0, -cost});
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BellmanFord(int &flow, long long &cost) {
		FOR0(i, n) {
			d[i] = INFLL;
		}
		memset(inq, 0, sizeof(inq));
		d[s] = 0, inq[s] = 1, p[s] = 0, a[s] = INF;

		queue<int> Q;
		Q.push(s);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			inq[u] = 0;
			FOR0(i, G[u].size()) {
				Edge &e = edges[G[u][i]];
				if (e.cap > e.flow && d[e.to] > e.cost + d[u]) {
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if (!inq[e.to]) {
						Q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
		if (d[t] == INFLL) return false;
		flow += a[t];
		cost += d[t] * a[t];
		int u = t;
		while (u != s) {
			edges[p[u]].flow += a[t];
			edges[p[u] ^ 1].flow -= a[t];
			u = edges[p[u]].from;
		}
		return true;
	}

	long long minCostMaxFlow(int s, int t) {
		this -> s = s, this -> t = t;
		flow = 0;
		long long cost = 0;
		while (BellmanFord(flow, cost));
		return cost;
	}
	void ini(int n) {
		this -> n = n;
		FOR0(i, n) {
			G[i].clear();
		}
		edges.clear();
	}	
};

//============================



int main(){
    
    return 0;
}