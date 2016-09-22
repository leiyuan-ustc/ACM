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

int T, N, M;
//============================



int main(){
	cin >> T;
	while (T--) {
		cin >> N >> M;
		if (N > 5502) {
			vector<int> ans(N + 1, -1);
			int x[5510],y[5510];
			FOR1(i, N) ans[i]=1;
			FOR1(i, M)
			{
				cin>>x[i]>>y[i];
			}
			int s;
			cin>>s;
			FOR1(i, M)
			{
				if (x[i]==s) ans[y[i]]=2;
				else if (y[i]==s) ans[x[i]]=2;
			}
			FOR1(i, N)
			 if (i!=s) cout<<ans[i]<<" ";
			cout<<endl; 
		}
		else {
			vector<vector<bool> > f(N + 1, vector<bool>(N + 1, true));
			FOR0(i, M) {
				int a, b;
				cin >> a >> b;
				f[a][b] = f[b][a] = 0;
			}

			int s;
			cin >> s;
			vector<int> ans(N + 1, -1);
			ans[s] = 0;
			queue<int> Q;
			Q.push(s);
			vector<bool> vis(N + 1);
			vis[s] = true;

			while (!Q.empty()) {
			  int now = Q.front();
			  Q.pop();
			  FOR1(i, N) {
			    if (f[now][i] && !vis[i]) {
			      ans[i] = ans[now] + 1;
			      Q.push(i);
			      vis[i] = 1;
			    }
			  }
			}
			FOR1(i, N)
			 if (i!=s) cout<<ans[i]<<" ";
			cout<<endl; 
		}
	}
    return 0;
}