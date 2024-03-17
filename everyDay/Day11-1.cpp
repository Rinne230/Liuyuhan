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
const ll N = 55;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
char g[N][N];
bool st[N][N];
vector<pll> blk[2];

void dfs(int op, int x, int y){
    st[x][y] = true;
    blk[op].push_back({x, y});
    for (int i = 0; i < 4; ++i){
        int tx = x + d[i][0], ty = y + d[i][1];
        if (st[tx][ty] || tx < 1 || tx > n || ty < 1 || ty > m || g[tx][ty] == '.'){
            continue;
        }
        dfs(op, tx, ty);
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> g[i][j];
        }
    }
    int op = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (!st[i][j] && g[i][j] == 'X'){
                dfs(op++, i, j);
            }
        }
    }
    int ans = inf32;
    for (auto [x1, y1] : blk[0]){
        for (auto [x2, y2] : blk[1]){
            ans = min(ans, abs(x1 - x2) + abs(y1 - y2) - 1);
        }
    }
    cout << ans << endl;
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