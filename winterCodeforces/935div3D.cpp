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
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n + 2), b(n + 2), fa(n + 2);
    vi suf(n + 2);
    vi dp(n + 2, inf64);
    dp[n + 1] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = n; i >= 1; --i){
        suf[i] = suf[i + 1] + b[i];
    }
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, n + 1});
    for (int i = n; i >= 1; --i){
        auto [val, idx] = q.top();
        dp[i] = dp[idx] + a[i] - b[i];
        q.push({dp[i], i});
    }
    //cout << "ANS :: ";
    //for (int i = 1; i <= m; ++i) cout << dp[i] + suf[i] << " \n"[i == m];
    int ans = inf64;
    for (int i = 1; i <= m; ++i) ans = min(ans, dp[i] + suf[i]);
    cout << ans << endl;
}

signed main(){
    lyh;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}