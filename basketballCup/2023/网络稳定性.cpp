#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
#define int ll
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct edge
{
    int u, v, w;
};

int fa[N][20], mn[N][20];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    memset(mn, 0x3f, sizeof mn);
    vi f(n + 1), dep(n + 1);
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    vector<edge> e(m + 1);
    vector<vector<pll>> G(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(all(e), [&](edge a, edge b)
         { return a.w > b.w; });
    function<int(int)> find = [&](int x)
    {
        return f[x] == x ? x : f[x] = find(f[x]);
    };
    for (int i = 1, cnt = 0; i <= m && cnt < n - 1; ++i)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (find(u) != find(v))
        {
            f[find(v)] = find(u);
            ++cnt;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }
    function<void(int, int)> dfs = [&](int u, int fr)
    {
        dep[u] = dep[fr] + 1;
        fa[u][0] = fr;
        for (int i = 1; (1 << i) < dep[u]; ++i){
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
            mn[u][i] = min(mn[u][i - 1], mn[fa[u][i - 1]][i - 1]);
        }
        for (auto [v, w] : G[u]){
            if (v == fr) continue;
            mn[v][0] = w;
            dfs(v, u);
        }

    };
    for (int i = 1; i <= n; ++i){
        if (!dep[i]){
            dfs(i, 0);
        }
    }
    function<int(int, int)> lca = [&](int u, int v){
        if (u == v) return 0ll;
        int ans = inf64;
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = 19; i >= 0; --i){
            if (dep[fa[v][i]] >= dep[u]){
                ans = min(ans, mn[v][i]);
                v = fa[v][i];
            }
        }
        if (u == v) return ans;
        for (int i = 19; i >= 0; --i){
            if (fa[u][i] != fa[v][i]){
                ans = min(ans, min(mn[u][i], mn[v][i]));
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return min(ans, min(mn[u][0], mn[v][0]));
    };
    
    while (q--){
        int u, v;
        cin >> u >> v;
        int fu = find(u), fv = find(v);
        if (fu != fv){
            cout << -1 << endl;
            continue;
        }
        cout << lca(u, v) << endl;
    }
}

signed main()
{
    ios;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}