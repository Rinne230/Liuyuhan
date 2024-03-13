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

int cal(int x)
{
    int cnt;
    if (x == 0)
        return 1;
    for (cnt = 0; x > 0; x /= 10)
        ++cnt;
    return cnt;
}

void solve()
{
    int a, b, c, d, _, n, x, y;
    set<int> ans;
    string s;
    cin >> n >> s >> y;
    for (a = 0; a < 10; ++a)
        for (b = 0; b < 10; ++b)
            for (c = 0; c < 10; ++c)
                for (d = 0; d < 10; ++d)
                {
                    set<int> res = {a, b, c, d};
                    if (res.size() != 4)
                        continue;
                    for (_ = 0; _ < 10; ++_)
                    {
                        x = 0;
                        for (char &sc : s)
                        {
                            if (sc == 'a')
                                x = x * 10 + a;
                            else if (sc == 'b')
                                x = x * 10 + b;
                            else if (sc == 'c')
                                x = x * 10 + c;
                            else if (sc == 'd')
                                x = x * 10 + d;
                            else if (sc == '_')
                                x = x * 10 + _;
                            else
                                x = x * 10 + (sc ^ 48);
                        }
                        if (cal(x) == n && x % 8 == 0 && x <= y)
                            ans.emplace(x);
                    }
                }
    cout << ans.size() << '\n';
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