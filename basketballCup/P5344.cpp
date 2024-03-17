// 倍增优化建图
#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int inf = 0x3f3f3f3f;
const int N = 50050, M = 1000050, NE = 4000050, ME = 16000050;

int l, tot, fa[N], to[N << 1], nxt[N << 1], head[N], dep[N], f[N][16], in[N][16], ot[N][16];
struct edge
{
    int v, d, n;
} e[ME];
struct opers
{
    int x1, y1, x2, y2, w;
} ops[M];
int ted;
int cnt, hd[NE], t;
int dis[NE];

inline bool cmp(int x, int y) { return dis[x] < dis[y]; }

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void addtree(int u, int v)
{
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    to[++tot] = u;
    nxt[tot] = head[v];
    head[v] = tot;
}

void addedge(int u, int v, int d)
{
    e[++t] = {v, d, hd[u]};
    hd[u] = t;
}

void dfs(int x, int fr)
{
    dep[x] = dep[f[x][0] = fr] + 1;
    in[x][0] = ++cnt, addedge(cnt, x, 0), addedge(cnt, fr, 0);
    ot[x][0] = ++cnt, addedge(x, cnt, 0), addedge(fr, cnt, 0);
    for (int j = 1; j <= l; ++j)
    {
        f[x][j] = f[f[x][j - 1]][j - 1];
        in[x][j] = ++cnt, addedge(cnt, in[x][j - 1], 0), addedge(cnt, in[f[x][j - 1]][j - 1], 0);
        ot[x][j] = ++cnt, addedge(ot[x][j - 1], cnt, 0), addedge(ot[f[x][j - 1]][j - 1], cnt, 0);
    }
    for (int i = head[x]; i; i = nxt[i])    
    {
        if (to[i] == fr)
            continue;
        dfs(to[i], x);
    }
}

inline void lca1(int x, int y, int k)
{
    if (dep[x] < dep[y])
        x ^= y ^= x ^= y;
    addedge(y, k, 0);
    for (int i = l; i >= 0; --i)
    {
        if (dep[f[x][i]] >= dep[y])
        {
            addedge(ot[x][i], k, 0);
            x = f[x][i];
        }
    }
    if (x == y)
        return;
    for (int i = l; i >= 0; --i)
    {
        if (f[x][i] != f[y][i])
        {
            addedge(ot[x][i], k, 0);
            addedge(ot[y][i], k, 0);
            x = f[x][i];
            y = f[y][i];
        }
    }
    addedge(ot[x][0], k, 0);
}

inline void lca2(int x, int y, int k)
{
    if (dep[x] < dep[y])
        x ^= y ^= x ^= y;
    addedge(k, y, 0);
    for (int i = l; i >= 0; --i)
    {
        if (dep[f[x][i]] >= dep[y])
        {
            addedge(k, in[x][i], 0);
            x = f[x][i];
        }
    }
    if (x == y)
        return;
    for (int i = l; i >= 0; --i)
    {
        if (f[x][i] != f[y][i])
        {
            addedge(k, in[x][i], 0);
            addedge(k, in[y][i], 0);
            x = f[x][i];
            y = f[y][i];
        }
    }
    addedge(k, in[x][0], 0);
}

inline void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        auto [ds, u] = q.top();
        q.pop();
        if (ds > dis[u])
            continue;
        for (int i = hd[u]; i; i = e[i].n)
        {
            int v = e[i].v;
            if (dis[v] > ds + e[i].d)
            {
                q.push({dis[v] = ds + e[i].d, v});
            }
        }
    }
}

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    cnt = n;
    while ((1 << l) <= n)
        l++;
    l--;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x1, y1, x2, y2, w;
            cin >> x1 >> y1 >> x2 >> y2 >> w;
            if (find(x1) != find(y1) || find(x2) != find(y2))
            {
                continue;
            }
            ops[++ted] = {x1, y1, x2, y2, w};
        }
        else
        {
            int x1, y1, w;
            cin >> x1 >> y1 >> w;
            int fx = find(x1), fy = find(y1);
            if (fx == fy)
                continue;
            fa[fx] = fy;
            addtree(x1, y1);
            addedge(x1, y1, w);
            addedge(y1, x1, w);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!dep[i])
            dfs(i, 0);
    for (int i = 1; i <= ted; ++i)
    {
        lca1(ops[i].x1, ops[i].y1, ++cnt);
        lca2(ops[i].x2, ops[i].y2, ++cnt);
        addedge(cnt - 1, cnt, ops[i].w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; ++i)
        cout << (dis[i] == inf ? -1 : dis[i]) << " ";
    cout << endl;
}

signed main()
{
    lyh;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}