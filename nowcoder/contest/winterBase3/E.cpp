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
const ll maxk = 1e2 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

//前 i 个元素中，最多进行 j 次交换，且最后一个元素在位置 t 的情况下，可以得到的最大子段和
int dp[2][maxk][maxn], f[maxn][maxk], g[maxn][maxk], pre[maxn][maxk];
int a[maxn];
int n, k;

void calc(){
    for (int j = 0; j <= k; ++j){
        for (int t = 0; t <= n; ++t){
            dp[0][j][t] = -inf64;
        }
    }  
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= k; ++j){
            pre[i][j] = 0;
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i){
        int cur = i & 1;
        for (int j = 0; j <= k; ++j){
            for (int t = 0; t <= n; ++t){
                dp[cur][j][t] = -inf64;
            }
        }
        for (int j = 0; j <= k; ++j){
            for (int t = 0; t <= i; ++t){
                if (t) dp[cur][j][t] = dp[cur ^ 1][j][t - 1] + a[i];
                if (j >= t) dp[cur][j][t] = max(dp[cur][j][t], dp[cur ^ 1][j - t][t]);
            }
            for (int t = 0; t <= i; ++t){
                pre[i][j] = max(pre[i][j], dp[cur][j][t]);
            }
            if (j) pre[i][j] = max(pre[i][j], pre[i][j - 1]); 
            //前 i 个元素中，最多进行 j 次交换可以得到的最子段和
        }
    }
}
void solve(){
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    calc();
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= k; ++j){
            f[i][j] = pre[i][j];
        }
    }
    reverse(a + 1, a + n + 1);
    calc();
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= k; ++j){
            g[n - i + 1][j] = pre[i][j];
        }
    }
    reverse(a + 1, a + n + 1);
    vi s(n + 1, 0);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    int ans = -inf64;
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            for (int t = 0; t <= k; ++t){
                ans = max(ans, f[i - 1][t] + g[j + 1][k - t] + s[j] - s[i - 1]);
            }
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