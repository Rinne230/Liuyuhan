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

int dp[101][101];
void solve(){
    for (int i = 0; i < 101; ++i){
        for (int j = 0; j < 101; ++j){
            dp[i][j] = inf32;
        }
    }
    string T;
    cin >> T;
    int n;
    cin >> n;
    vector<vector<string>> S(n + 1);
    for (int i = 1; i <= n; ++i){
        int m = 0;
        cin >> m;
        S[i].resize(m);
        for (int j = 0; j < m; ++j){
            cin >> S[i][j];
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < S[i].size(); ++j){
            for (int k = 0; k <= T.size(); ++k){
                string ts = S[i][j];
                dp[i][k] = min(dp[i][k], dp[i - 1][k]);
                if (ts.size() > k) continue;
                if (ts == T.substr(k - ts.size(), ts.size())){
                    dp[i][k] = min(dp[i][k], dp[i - 1][k - ts.size()] + 1);
                }
            }
        }
    }
    int ans = inf32;
    for (int i = 1; i <= n; ++i){
        ans = min(ans, dp[i][T.size()]);
    }
    if (ans == inf32)
        cout << -1 << endl;
    else
        cout << ans << endl;
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