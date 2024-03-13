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
const ll maxn = 51;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int C[maxn][maxn];
void init()
{
    C[0][0] = 1;
    rep(i, 1, 50)
    {
        C[i][0] = 1;
        rep(j, 1, i)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
        }
    }
}

int nCr(int n, int m)
{
    if (n < m)
        return 0;
    return C[n][m];
}

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    int ans = 0;
    for (int i = 1; i <= t - 4; ++i){
        ans += nCr(m, i) * nCr(n, t - i);
    }
    cout << ans << endl;
}

signed main()
{
    ios;
    init();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}