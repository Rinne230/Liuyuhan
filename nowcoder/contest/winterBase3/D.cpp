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
    int n, k;
    cin >> n >> k;
    vi a(n + 1), sum(n + 1);
    rep(i, 1, n) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    int ans = -inf64;
    rep(i, 1, n)
    {
        rep(j, i, n)
        {
            int tmp = sum[j] - sum[i - 1];
            if (k == 1)
            {
                if (i > 1)
                    ans = max(ans, tmp + a[i - 1] - a[i]);
                if (j < n)
                    ans = max(ans, tmp + a[j + 1] - a[j]);
                
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}