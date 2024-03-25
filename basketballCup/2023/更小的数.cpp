#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 5e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int dp[N][N];

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    int ans = 0;
    for (int i = 1; i <= n - 1; ++i){
        if (s[i] > s[i + 1])
            dp[i][i + 1] = 1; 
    }
    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len <= n; ++i){
            if (s[i] == s[i + len]) dp[i][i + len] = dp[i + 1][i + len - 1];
            if (s[i] > s[i + len]) dp[i][i + len] = 1;
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            ans += dp[i][j];
        }
    }
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