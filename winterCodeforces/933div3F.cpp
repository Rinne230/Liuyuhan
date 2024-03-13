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
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), d(m), f(k);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> f[i];
    }

    sort(d.begin(), d.end());
    sort(f.begin(), f.end());

    int mx1 = 0, p = 0, mx2;
    for (int i = 2; i <= n; i++)
    {
        int t = (a[i] - a[i - 1]);
        if (t >= mx1)
        {
            p = i;
            mx2 = mx1;
            mx1 = t;
        }
        else if (t > mx2)
        {
            mx2 = t;
        }
    }

    int ans = mx1;
    for (int i = 0; i < m; i++)
    {
        auto it = lower_bound(f.begin(), f.end(), a[p - 1] - d[i]);
        while (it != f.end())
        {
            if (*it + d[i] >= a[p])
                break;
            ans = min(ans, max({mx2, a[p] - *it - d[i], *it + d[i] - a[p - 1]}));
            it++;
        }
    }
    cout << ans << "\n";
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