#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
bitset<1010> f[10010];
int c[1010];
int N, Q;
int main()
{
		scanf("%d", &N);
        int t, a, b;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &c[i]);
            for(int j = 0; j < c[i]; j++)
            {
                scanf("%d", &t);
                f[t].set(i);
            }
        }
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++)
        {
            scanf("%d%d", &a, &b);
            if ((f[a] & f[b]).any()) printf("Yes\n");
            else printf("No\n");
            
        }
    

    return 0;
}