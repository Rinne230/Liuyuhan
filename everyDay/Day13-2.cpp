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

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void solve(){
    int n;
    cin >> n;
    vector g(n + 1, vector<char>(n + 1));
    vector st(n + 1, vector<int>(n + 1, 0));
    vector ok(n + 1, vector<int>(n + 1, 1));
    rep(i, 1, n){
        rep(j, 1, n){
            cin >> g[i][j];
        }
    }
    rep(i, 1, n)
        rep(j, 1, n){
            for (int k = 0; k < 4; ++k){
                int x = i + d[k][0], y = j + d[k][1];
                if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] == '.'){
                    ok[i][j] = 0;
                }
            }
        }
    bool flag = 0;
    function<void(int, int)> dfs = [&](int x, int y){
        st[x][y] = 1;
        if (ok[x][y]){
            flag = 1;
        }
        for (int k = 0; k < 4; ++k){
            int xx = x + d[k][0], yy = y + d[k][1];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && g[xx][yy] == '#' && !st[xx][yy]){
                dfs(xx, yy);
            }
        }
    };
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; ++j){
            flag = 0;
            if (!st[i][j] && g[i][j] == '#'){
                ans++;
                dfs(i, j);
            }
            if (flag) ans--;
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