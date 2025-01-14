/**
 * tree
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int MXN = 500012;

int n, m;
long long ans;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP *get_mem() {
        for (s = NULL; !s;) s = (TYP *)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s++;
    }

   public:
    MemPool() { SIZ = 1 + 1048576 / sizeof(TYP), s = e = NULL; }
    TYP *operator()() { return (s < e) ? (s++) : (get_mem()); }
};

struct Edge {
    int v;
    Edge *next;
} * edge[MXN];
MemPool<Edge> ep;
inline void add_edge(int u, int v) {
    Edge *p = ep();
    p->v = v;
    p->next = edge[u], edge[u] = p;
}

int dep[MXN], arr[MXN][22];

void pre(int x, int f, int d) {
    dep[x] = d;
    for (Edge *i = edge[x]; i; i = i->next)
        if (i->v != f)
            arr[i->v][0] = x, pre(i->v, x, d + 1);
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) x ^= y ^= x ^= y;
    for (int i = 20; i >= 0; --i)
        if (dep[arr[x][i]] >= dep[y])
            x = arr[x][i];
    for (int i = 20; i >= 0; --i)
        if (arr[x][i] != arr[y][i])
            x = arr[x][i], y = arr[y][i];
    return (x == y) ? (x) : (arr[x][0]);
}

int tag[MXN] = {};
int sum[MXN];
void dfs(int x, int f) {
    sum[x] += tag[x];
    for (Edge *i = edge[x]; i; i = i->next)
        if (i->v != f)
            dfs(i->v, x), sum[x] += sum[i->v];
}

signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 1, x, y; i < n; ++i)
        scanf("%d%d", &x, &y), add_edge(x, y), add_edge(y, x);

    pre(1, 0, 1);
    for (int i = 0, j; i < 20; ++i)
        for (j = 1; j <= n; ++j)
            arr[j][i + 1] = arr[arr[j][i]][i];

    for (int i = 0, x, y; i < m; ++i)
        scanf("%d%d", &x, &y),
            ++tag[x], ++tag[y], tag[lca(x, y)] -= 2;
    dfs(1, 0);
    for (int i = 2; i <= n; ++i)
        if (sum[i] == 0)
            ans += m;
        else if (sum[i] == 1)
            ++ans;

    printf("%lld", ans);

    return 0;
}