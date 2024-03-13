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
    int n, w, k;
    cin >> n >> w >> k;
    vector<pll> itm(n + 1);
    vector <int> suf(n + 2);
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -inf64));
    priority_queue <int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i){
        cin >> itm[i].x >> itm[i].y;
    }
    sort(itm.begin() + 1, itm.end(), [&](pll p, pll q){
        return p.x < q.x;
    });
    for(int i = n; i >= 1; i--) {
        if(q.size() < k) {
            suf[i] = suf[i + 1] + itm[i].y;
            q.push(itm[i].y);
        }
        else if(k) {
            suf[i] = suf[i + 1] + itm[i].y;
            q.push(itm[i].y);
            suf[i] -= q.top(), q.pop();
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = w; j >= itm[i].x; --j){
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i - 1][j - itm[i].x] + itm[i].y, dp[i][j]);
        }
        for (int j = 0; j < itm[i].x; ++j) dp[i][j] = dp[i - 1][j];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= w; ++j){
            ans = max(dp[i][j] + suf[i + 1], ans);
        }
    } 
    // for (int i = 1; i <= n; ++i){
    //     cout << suf[i] << " \n"[i == n];
    // }
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