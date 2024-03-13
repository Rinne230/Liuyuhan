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
    int a, b, r;
    int hi;
    cin >> a >> b >> r;
    if (a < b)
        swap(a, b);
    bool ok = 0;
    for (int i = 63; i >= 0; --i)
    {
        int x = (a >> i) & 1;
        int y = (b >> i) & 1;
        if (x == y)
            continue;
        else
        {
            if (!ok)
            {
                ok = 1;
                continue;
            }
            if ((1ll << i) > r)
                continue;
            if (((a >> i) & 1) == 1 && ((b >> i) & 1) == 0){
                a ^= (1ll << i);
                b ^= (1ll << i);
                r -= (1ll << i);
            }
        }
    }
    cout << a - b << endl;
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