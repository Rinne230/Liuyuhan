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
const ll maxn = 3e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int dp[5005][5005];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1), b(n + 1);
    vi cost(n + 1);
    rep(i, 0, n){
        cost[i] = 1e18;
    }
    rep(i, 1, m){
        cin >> a[i] >> b[i];
        rep(j, 1, n){
            int idx = j * a[i] % n;
            if (!idx) idx = n;
            cost[idx] = min(cost[idx], b[i] * j);
        }
    }
    rep(i, 1, n){
        if (i == k) dp[0][i] = 0;
        else dp[0][i] = inf64;
    }
    rep(i, 1, n){ 
        rep(j, 1, n){
            dp[i][j] = dp[i - 1][j];
        }
        rep(j, 1, n){
            int idx = (j + i) % n;
            if (!idx) idx = n;
            dp[i][idx] = min(dp[i][idx], dp[i - 1][j] + cost[i]);
        }
    }
    if (dp[n][n] == inf64) cout << -1 << endl;
    else cout << dp[n][n] << endl;
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