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
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i, 0, n - 1)
    {
        cin >> a[i];
    }
    rep(i, 0, m - 1)
    {
        cin >> b[i];
    }
    ll mxa, mxb, mna, mnb, curmn, curmx;
    mxa = mxb = -inf32;
    mna = mnb = inf32;
    curmn = curmx = 0;
    rep(i, 0, n - 1)
    {
        curmn += a[i];
        curmx += a[i];
        if (curmn > 0)
            curmn = 0;
        if (curmx < 0)
            curmx = 0;
        mna = min(mna, curmn);
        mxa = max(mxa, curmx);
    }
    curmn = curmx = 0;
    rep(i, 0, m - 1)
    {
        curmn += b[i];
        curmx += b[i];
        if (curmn > 0)
            curmn = 0;
        if (curmx < 0)
            curmx = 0;
        mnb = min(mnb, curmn);
        mxb = max(mxb, curmx);
    }
    curmn = inf32;
    curmx = -inf32;
    rep(i, 0, n - 1)
    {
        curmn = min(curmn, a[i]);
        curmx = max(curmx, a[i]);
    }
    if (curmx <= 0)
        mxa = min(mxa, curmx);
    if (curmn >= 0)
        mna = max(mna, curmn);
    curmn = inf32;
    curmx = -inf32;
    rep(i, 0, m - 1)
    {
        curmn = min(curmn, b[i]);
        curmx = max(curmx, b[i]);
    }
    if (curmx <= 0)
        mxb = min(mxb, curmx);
    if (curmn >= 0)
        mnb = max(mnb, curmn);
    cout << max({mna * mnb, mna * mxb, mxa * mnb, mxa * mxb}) << endl;
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