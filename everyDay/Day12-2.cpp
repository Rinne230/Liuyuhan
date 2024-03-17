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

int dp[1 << 20], t[101];
void solve(){
    fill(dp, dp + (1 << 20), inf32);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= k; ++j){
            int x;
            cin >> x;
            x--;
            t[i] |= (1 << x);
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < (1 << m); ++j){
            dp[j | t[i]] = min(dp[j | t[i]], dp[j] + 1);
        }
    }
    cout << (dp[(1 << m) - 1] == inf32 ? -1 : dp[(1 << m) - 1]) << endl;
}

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}