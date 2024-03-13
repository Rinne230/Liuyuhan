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
const ll N = 85;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int P[N][N], R[N][N], D[N][N];
int dp[N][N][2];
int dist[N][N];

void solve(){
    int n;
    cin >> n;
    rep(i, 1, n){
        rep(j, 1, n){
            cin >> P[i][j];
        }
    }
    rep(i, 1, n){
        rep(j, 1, n - 1){
            cin >> R[i][j];
        }
    }
    rep(i, 1, n - 1){
        rep(j, 1, n){
            cin >> D[i][j];
        }
    }
    rep(i, 1, n){
        rep(j, 1, n){
            dp[i][j][1] = 0;
            dp[i][j][0] = inf64;
        }
    }
    dp[1][1][0] = dp[1][1][1] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            for (int x = 1; x <= i; ++x)
                for (int y = 1; y <= j; ++y){
                    dist[x][y] = inf64;
                }
            dist[i][j] = 0;
            for (int x = i; x >= 1; --x)
                for (int y = j; y >= 1; --y){
                    if (x < i) dist[x][y] = min(dist[x][y], dist[x + 1][y] + D[x][y]);
                    if (y < j) dist[x][y] = min(dist[x][y], dist[x][y + 1] + R[x][y]);
                    int c = max(0ll, (dist[x][y] - dp[x][y][1] + P[x][y] - 1) / P[x][y]);
                    int t = dp[x][y][0] + c + i - x + j - y;
                    int m = dp[x][y][1] + c * P[x][y] - dist[x][y];
                    if (t < dp[i][j][0] || (t == dp[i][j][0] && m > dp[i][j][1])){
                        dp[i][j][0] = t, dp[i][j][1] = m;
                    }
                }
        }
    cout << dp[n][n][0] << endl;
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