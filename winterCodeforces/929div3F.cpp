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
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m + 1));
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j) 
            cin >> a[i][j];
    vector dp(n, vector<int>(m + 1, inf32));
    dp[0][1] = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 0; j < n; ++j){
            if (a[j][i]) continue;
            dp[j][i] = min(dp[j][i], dp[(j - 1 + n) % n][i - 1] + 1);
        }
        for (int j = 0; j < 3 * n; ++j){
            if (a[j % n][i] || a[(j - 1 + n) % n][i]) continue;
            dp[j % n][i] = min(dp[j % n][i], dp[(j - 2 + n) % n][i] + 1);
        }
    }
    int ans = inf32;
    for (int i = 0; i < n; ++i){
        if (dp[i][m] == inf32) continue;
        int npos = ((n - 1) + dp[i][m]) % n;
        if (npos < i) npos += n;
        int cur = dp[i][m] + min(npos - i, n - (npos - i));
        ans = min(ans, cur);
    }
    if (ans == inf32) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}