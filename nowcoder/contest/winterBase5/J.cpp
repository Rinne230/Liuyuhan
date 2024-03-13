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
    int n;
    cin >> n;
    vector<pll> ve(n);
    for (auto &[l, r] : ve){
        cin >> l >> r;
    }
    int L = 1, R = inf32;
    vector<vector<int>> v;
    for (auto &[l, r] : ve){
        if (L > r || R < l){
            v.push_back({L, R});
            L = l, R = r;
        }
        L = max(L, l);
        R = min(R, r);  
    }
    v.push_back({L, R});
    vector dp(v.size(), vector<int>(2, 0ll));
    for (int i = 1; i < v.size(); ++i){
        dp[i][0] = min(dp[i - 1][0] + abs(v[i][0] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][0] - v[i - 1][1]));
        dp[i][1] = min(dp[i - 1][0] + abs(v[i][1] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][1] - v[i - 1][1]));
    }
    cout << min(dp.back()[0], dp.back()[1]) << endl;
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