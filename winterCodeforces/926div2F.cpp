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
const ll maxn = 5e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int fac[maxn];

void init()
{
    fac[0] = 1;
    rep(i, 1, maxn - 1) fac[i] = fac[i - 1] * i % mod;
}

struct node
{
    int lc, rc, val;
};

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a)
{
    return qmi(a, mod - 2);
}

ll Comb(ll a, ll b)
{
    if (b > a || b < 0)
        return 0;
    ll fz = 1;
    for (int i = a - b + 1; i <= a; i++)
        fz = fz * i % mod;
    return fz * inv(fac[b]) % mod;
}

void solve()
{
    int n, C, idx = 0;
    cin >> n >> C;
    vector<node> a(n + 1);
    vector<int> c(n + 1);
    rep(i, 1, n){
        cin >> a[i].lc >> a[i].rc >> a[i].val;
    }
    function<void(int)> dfs =[&](int u){
        if(u == -1) return;
        dfs(a[u].lc);
        c[++idx] = a[u].val;
        dfs(a[u].rc);
    };
    dfs(1);
    int ans = 1;
    for (int i = 1, p = 0, l = 1, r, q; i <= n; ++i){
        if (c[i] == -1) p++;
        if (c[i] != -1 || i == n){
            r = (c[i] != -1 ? c[i] : C);
            q = r - l + 1;
            l = r;
            ans = ans * Comb(q + p - 1, p) % mod;
            p = 0;
        }
    }
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