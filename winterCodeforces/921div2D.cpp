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
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int qpow(int a, int b)
{
    if (b == 0)
        return 1;
    if (a == 0)
        return 0;
    int res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = (1ll * res * a) % mod;
        b >>= 1;
        a = (1ll * a * a) % mod;
    }
    return res;
}
int fact[maxn], inv[maxn];
void init()
{
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < maxn; i++)
        fact[i] = (i * fact[i - 1]) % mod;
    for (int i = 1; i < maxn; i++)
        inv[i] = qpow(fact[i], mod - 2);
}
int C(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    if (n == r)
        return 1;
    if (r == 0)
        return 1;
    return (((fact[n] * inv[r]) % mod) * inv[n - r]) % mod;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int sum = 0;
    for (int i = 0, a, b, f; i < m; ++i)
    {
        cin >> a >> b >> f;
        sum = (sum + f) % mod;
    }
    int fm = (n * (n - 1) / 2ll) % mod;
    int invfm = qpow(fm, mod - 2);
    int ans1 = ((sum * k) % mod) * invfm % mod;
    int pred = 0;
    for (int i = 1; i <= k; ++i)
    {
        int sum = (i * (i - 1) / 2ll) % mod;
        int p = (C(k, i) * qpow(invfm, i)) % mod;
        int up = ((fm - 1) * invfm) % mod;
        up = qpow(up, k - i) % mod;
        p = (p * up) % mod;
        pred = (pred + (p * sum) % mod) % mod;
    }
    int ans = (ans1 + (m * pred) % mod) % mod;
    cout << ans << endl;
}

signed main()
{
    ios;
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}