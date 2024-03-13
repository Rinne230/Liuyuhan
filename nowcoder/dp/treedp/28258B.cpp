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
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    int n;
    cin >> n;
    vi h(n + 1), isH(n + 1);
    vector<vi> G(n + 1);
    vector dp(n + 1, vi(2, 0));
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        isH[u] = 1;
        G[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int u, int fa)
    {
        dp[u][1] = h[u];
        for (auto v : G[u])
        {
            if (v == fa)
                continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][1], dp[v][0]);
            dp[u][1] += dp[v][0];
        }
    };
    for (int i = 1; i <= n; ++i)
    {
        if (!isH[i])
        {
            dfs(i, i);
            cout << max(dp[i][1], dp[i][0]) << endl;
            return;
        }
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