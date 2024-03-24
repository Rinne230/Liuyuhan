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
const ll N = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int qmi(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n, k, s = 0;
    cin >> n >> k;
    vi a(n + 1), dp(n + 1);
    rep(i, 1, n) cin >> a[i], s = (s + a[i] + mod) % mod;
    int mx = 0;
    rep(i, 1, n){
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        mx = max(mx, dp[i]);
    }
    //cout << mx << endl;
    mx += mod;
    cout << (((mx) % mod * qmi(2, k) % mod - mx + mod + s) % mod + mod) % mod<< endl;
    
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