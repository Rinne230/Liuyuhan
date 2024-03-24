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
    int n, x;
    cin >> n >> x;
    x++;
    vi a(n);
    int res = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int j = 30; j >= 0; --j)
    {
        vector<int> sec;
        bool st = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (!st)
            {
                sec.push_back(a[i]);
            }
            else
            {
                sec.back() ^= a[i];
            }
            if (a[i] & (1 << j))
            {
                st = !st;
            }
        }
        if (!(x & (1 << j)))
        {
            if (st)
            {
                cout << res << endl;
                return;
            }
            a = sec;
        }
        else
        {
            if (!st)
                res = max(res, ll(sec.size()));
        }
    }
    cout << res << endl;
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