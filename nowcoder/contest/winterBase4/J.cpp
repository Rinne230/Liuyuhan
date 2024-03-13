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
const ll maxn = 23;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

pll a[maxn];
int n, d[maxn][maxn];
int dp[(1 << 20) + 100];

int cross(const pll & a, const pll & b){
    return a.x * b.y - a.y * b.x;
}

pll operator - (const pll & a, const pll & b){
    return {a.x - b.x, a.y - b.y};
}

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            if (i == j) continue;
            for (int k = 0; k < n; ++k){
                if (cross(a[i] - a[j], a[j] - a[k]) == 0) d[i][j] |= (1 << k);
            }
        }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; ++i){
        dp[1 << i] = 1;
        for (int j = 0; j < n; ++j){
            if (i == j) continue;
            dp[d[i][j]] = 1;
        }
    }
    for (int i = 1; i < (1 << n); ++i){
        for (int j = 0; j < n; ++j){
            if (i >> j & 1){
                for (int k = 0; k < n; ++k){
                    if (j == k) continue;
                    dp[i | d[j][k]] = min(dp[i | d[j][k]], dp[i] + 1);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
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