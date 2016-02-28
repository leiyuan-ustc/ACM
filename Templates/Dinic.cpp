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

using namespace std;
//============================
const int INF = (int)1e9 + 9;
const int maxn = 10010;

struct Edge
{
	int from, to, cap, flow;
};

struct Dinic
{
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	int cur[maxn], d[maxn];
	bool vis[maxn];

	void addEdge(int from, int to, int cap) {
		edges.push_back((Edge){from, to, cap, 0});
		edges.push_back((Edge){to, from, 0, 0});
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BFS() {
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		vis[s] = 1;
		d[s] = 0;
		while (!Q.empty()) {
			int f = Q.front();
			Q.pop();
			FOR0 (i, G[f].size()) {
				Edge &now = edges[G[f][i]];
				if (!vis[now.to] && now.cap > now.flow) {
					vis[now.to] = 1;
					Q.push(now.to);
					d[now.to] = d[now.from] + 1;
				}
			}
		}
		return vis[t];
	}

	int DFS(int x, int a) {
		if (x == t || (!a)) return a;
		int flow = 0, f;
		for (int &i = cur[x]; i < G[x].size(); i++) {
			Edge &now = edges[G[x][i]];
			if (d[x] + 1 == d[now.to] && (f = DFS(now.to, min(a, now.cap - now.flow))) > 0) {
				now.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (!a) break;
			}
		}
		return flow;
	}

	int maxFlow(int s, int t) {
		this -> s = s, this -> t = t;
		int flow = 0;
		while (BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, INF);
		}
		return flow;
	}	
};

//============================



int main(){
    
    return 0;
}