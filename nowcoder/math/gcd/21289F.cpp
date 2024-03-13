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

int qpow(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int getPhi(int x)
{
    int res = 1;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            res = 1ll * res * (i - 1);
            x /= i;
            while (x % i == 0)
            {
                res = 1ll * res * i;
                x /= i;
            }
        }
    }
    if (x != 1)
        res = 1ll * res * (x - 1);
    return res;
}

void solve()
{
    string b, n;
    cin >> b >> n;
    int c;
    cin >> c;
    int ns = n.size(), bs = b.size();
    auto get_mod = [&](string s, int sz, int c)
    {
        int ret = 0;
        for (int i = 0; i < sz; ++i)
        {
            ret = (1ll * ret * 10 % c + s[i] - '0') % c;
        }
        return ret;
    };
    int bm = get_mod(b, bs, c);
    int left = (bm + c - 1) % c;
    int right = 0;
    if (ns < 11)
    {
        ll nn = stol(n);
        right = qpow(bm, nn - 1, c);
    }
    else
    {
        int phi = getPhi(c);
        int nm = get_mod(n, ns, phi);
        int e = (nm - 1) % phi + phi;
        right = qpow(bm, e, c);
    }
    int ans = 1ll * left * right % c;
    if (!ans)
        ans = c;
    cout << ans << '\n';
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