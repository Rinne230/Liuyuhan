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
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector dp(k + 1, vi(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        vector new_dp(k + 1, vi(k + 1, 0));
        for (int b = 0; b <= k; ++b)
        {
            for (int a = 0; a <= k; ++a)
            {
                int c = max(0ll, b - a);
                new_dp[b][c] = (new_dp[b][c] + dp[a][b]) % p;
                ;
            }
            for (int j = 1; j <= k; ++j)
                new_dp[b][j] = (new_dp[b][j] + new_dp[b][j - 1]);
        }
        dp = new_dp;
    }
    int ans = 0;
    for (int a = 0; a <= k; a++)
    {
        for (int b = 0; b <= a; b++)
        {
            ans = (ans + dp[a][b]) % p;
        }
    }
    cout << ans << endl;
}

signed main()
{
    lyh;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}