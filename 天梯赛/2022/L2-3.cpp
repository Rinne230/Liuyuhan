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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    int n, m, st;
    cin >> n >> m;
    vi f(n + 1);
    vi dep(n + 1, -1);
    vi vis(n + 1);
    vector<vi> G(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> f[i];
        if (f[i] != -1){
            G[f[i]].push_back(i);
        }else{
            st = i;
        }
    }
    int ans = 0;
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        dep[u] = dep[fa] + 1;
        for (auto v : G[u])
        {
            if (v == fa)
                continue;
            dfs1(v, u);
        }
    };
    dfs1(st, 0);
    auto check = [&](int x){
        while (!vis[x]){
            vis[x] = 1;
            x = f[x];
            if (x == -1) break;
            ans++;
            
        }
    };
    int mx = 0;
    for (int i = 1; i <= m; ++i){
        int x;
        cin >> x;
        check(x); 
        mx = max(mx, dep[x]);
        //cout << ans << " " << dep[x] << " ";
        cout << ans * 2 - mx << endl;
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