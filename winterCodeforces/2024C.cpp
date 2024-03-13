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
    vi a(n + 1);
    vi s, t;
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    int ans = 0;
    s.push_back(inf32);
    t.push_back(inf32);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] <= s.back() && a[i] <= t.back())
        {
            if (s.back() < t.back())
            {
                s.push_back(a[i]);
            }
            else
            {
                t.push_back(a[i]);
            }
        }
        else if (a[i] <= s.back() || a[i] <= t.back())
        {
            if (s.back() > t.back())
            {
                s.push_back(a[i]);
            }
            else
            {
                t.push_back(a[i]);
            }
        }
        else
        {
            if (s.back() < t.back())
            {
                s.push_back(a[i]);
            }
            else
            {
                t.push_back(a[i]);
            }
        }
    }
    for (int i = 2; i < s.size(); ++i) if (s[i] > s[i - 1]) ans++;
    for (int i = 2; i < t.size(); ++i) if (t[i] > t[i - 1]) ans++;
    cout << ans << endl;
}

signed main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}