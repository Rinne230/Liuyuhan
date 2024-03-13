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
const ll maxn = 1e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int a[maxn], dp[maxn][maxn][7][2], g[maxn], n;

void solve(){
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= 6; ++k) 
                dp[i][j][k][0] = inf64, dp[i][j][k][1] = -inf64;
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            for (int k = 1; k <= 6; ++k){
                if (k > j - i + 1) break;
                int fmin = dp[i][j - 1][k][0], fmax = dp[i][j - 1][k][1];
                if (k == 1){
                    fmin = min(fmin, a[j]);
                    fmax = max(fmax, a[j]); 
                }else if (k == 2 || k == 4 || k == 6){
                    fmin = min(fmin, dp[i][j - 1][k - 1][0] - a[j]);
                    fmax = max(fmax, dp[i][j - 1][k - 1][1] - a[j]);
                }else{
                    fmin = min({fmin, dp[i][j - 1][k - 1][0] * a[j], dp[i][j - 1][k - 1][1] * a[j]});
                    fmax = max({fmax, dp[i][j - 1][k - 1][0] * a[j], dp[i][j - 1][k - 1][1] * a[j]});
                }
                dp[i][j][k][0] = fmin, dp[i][j][k][1] = fmax;
            }
        }
    }
    for (int i = 6; i <= n; ++i){
        for (int j = 0; j <= i - 6; ++j){
            g[i] = max(g[i], g[j] + dp[j + 1][i][6][1]);
        }
    }
    cout << g[n] << endl;
}

signed main(){
    ios;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}