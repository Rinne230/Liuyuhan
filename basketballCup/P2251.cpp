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
const ll maxn = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int dp[maxn][30];
void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i][0] = a[i];
    }
    for (int j = 1; j <= 25; ++j){
        for (int i = 1; i + (1 << j) - 1 <= n; ++i){
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n - m + 1; ++i){
        int k = log2(m);
        cout << min(dp[i][k], dp[i + m - (1 << k)][k]) << endl;
    }
    
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