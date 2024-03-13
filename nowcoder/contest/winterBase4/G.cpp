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
    int n, m;
    cin >> n >> m;
    vector a(n + 2, vector<int>(m + 2));
    vector sum(n + 2, vector<int>(m + 2));
    rep(i, 1, n){
        rep(j, 1, m) {
            char ch;
            cin >> ch;
            if (ch == '*') a[i][j] = 1;
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    }
    vector dpl(n + 2, vector<int>(m + 2)), dpr(n + 2, vector<int>(m + 2));
    vector<pll> dot;
    for (int i = n - 1; i >= 1; --i){
        for (int j = 2; j <= m - 1; ++j){
            if (a[i][j] == 1){
                if (a[i + 1][j - 1] == 1) dpl[i][j] = dpl[i + 1][j - 1] + 1;
                if (a[i + 1][j + 1] == 1) dpr[i][j] = dpr[i + 1][j + 1] + 1;
                if (dpl[i][j] && dpr[i][j]) dot.push_back({i, j});
            } 
        }
    }
    // rep(i, 1, n)
    //     rep(j, 1, m)
    //         cout << dpl[i][j] << " \n"[j == m];
    // rep(i, 1, n)
    //     rep(j, 1, m)
    //         cout << dpr[i][j] << " \n"[j == m];        
    int ans = 0;
    for (auto [x, y] : dot){
        //cout << x << " " << y << " check" << endl;
        for (int i = 1; i <= min(dpl[x][y], dpr[x][y]); ++i){
           
            if (sum[x + i][y + i] - sum[x + i][y - i - 1] == (2 * i + 1)) ans++;
        }
    }
    cout << ans << endl;
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