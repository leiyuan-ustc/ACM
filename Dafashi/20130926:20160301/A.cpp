#include <cstdio>
#include <cstring>
using namespace std;
int f[1005][10005];
int c[1005];
int N, Q;
int main()
{
    while (scanf("%d", &N) != EOF)
    {
        int t, a, b;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &c[i]);
            for(int j = 0; j < c[i]; j++)
            {
                scanf("%d", &t);
                f[i][t]++;
            }
        }
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++)
        {
            scanf("%d%d", &a, &b);
            bool ok = 0;

            for (int j = 0; j < N; j++)
            {
                if (a == b)
                {
                    if (f[j][a] >= 2)
                    {
                        ok = 1;
                        break;
                    }
                }
                else
                {


                    if (f[j][a] && f[j][b] )
                    {
                        ok = 1;
                        break;
                    }
                }
            }
            if (ok)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}