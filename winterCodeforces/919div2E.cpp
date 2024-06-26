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
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int ans = 0;
    int n, k;
    cin >> n >> k;
    vector dp(n + 1, vi(k + 5, 0));
    for (int i = 1; i <= k; ++i) dp[0][i] = 1;
    for (int i = 0; i <= n - 1; ++i){
        for (int j = 1; j <= k; ++j){
            for (int t = 1; t <= k + 1 - j; ++t){
                if (i + j * t > n) break;
                dp[i + j * t][t] = (dp[i + j * t][t] + dp[i][j]) % mod;
            }
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= k; ++i){
        ans = (ans + dp[n][i]) % mod;
        dp[n][i] = 0;
    }
    cout << ans << endl;
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