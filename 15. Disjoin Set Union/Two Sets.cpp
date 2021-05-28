#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 5;
int n, a, b, p[MAX], fa[MAX];
map<int, int> mp;

// Union Find with Compression Path
int Find(int x)
{
    if (fa[x] != x)
        fa[x] = Find(fa[x]);
    return fa[x];
}

// Normal Union without Weighted Path
void Union(int u, int v)
{
    int uu = Find(u);
    int vv = Find(v);
    if (uu != vv)
        fa[uu] = v;
}

int main()
{
    if (scanf("%d%d%d", &n, &a, &b) == 3)
    {
        int Max = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i]);
            mp[p[i]] = i;   
            Max = max(Max, p[i]);
        }
        if (Max >= max(a, b))
            printf("NO\n");
        else
        {
            for (int i = 0; i <= n + 1; i++)
            {
                fa[i] = i;
            }
            for (int i = 1; i <= n; i++)
            {
                if (mp[a - p[i]])
                    Union(i, mp[a - p[i]]);
                else
                    Union(i, n + 1);
                if (mp[b - p[i]])
                    Union(i, mp[b - p[i]]);
                else
                    Union(i, 0);
            }
            int A = Find(0);
            int B = Find(n + 1);
            if (A != B)
            {
                printf("YES\n");
                for (int i = 1; i <= n; i++)
                {
                    if (i != 1)
                        printf(" ");
                    if (Find(i) == A)
                        printf("0");
                    else
                        printf("1");
                }
                printf("\n");
            }
            else
                printf("NO\n");
        }
    }
    return 0;
}

// Python
def find(u):
    global par
    if u != par[u]:
        par[u] = find(par[u])
    return par[u]

def union(u, v):
    u = find(u)
    v = find(v)
    par[u] = v

n, a, b = map(int, input().split())
p = list(map(int, input().split()))
mp = dict()
for i in range(n):
    mp[p[i]] = i + 1
par = [i for i in range(n + 2)]

for i in range(n):
    union(i + 1, mp.get(a - p[i], n + 1))
    union(i + 1, mp.get(b - p[i], 0))

A = find(0)
B = find(n + 1)

if A != B:
    print('YES')
    print(' '.join(['1' if find(i) == B else '0' for i in range(1, n + 1)]))
else:
    print('NO')	