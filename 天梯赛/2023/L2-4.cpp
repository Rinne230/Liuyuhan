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
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int cnt1 = 0, cnt2 = 0;
int ok = 0;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve(){
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<char>(m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j]; 
    vector st(n + 1, vector<int>(m + 1, 0));
    function<void(int, int)> bfs = [&](int x, int y){
        queue<pll> q;
        q.push({x, y});
        st[x][y] = 1;
        while(q.size()){
            auto [x, y] = q.front();
            q.pop();
            if (g[x][y] >= '2' && g[x][y] <= '9') ok = 1;
            rep(i, 0, 3){
                int nx = x + d[i][0], ny = y + d[i][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (g[nx][ny] == '0' || st[nx][ny]) continue;
                st[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    };
    rep(i, 1, n) rep(j, 1, m){
        if (!st[i][j] && g[i][j] >= '1' && g[i][j] <= '9'){
            ok = 0;
            cnt1++;
            bfs(i, j);
            if (ok) cnt2++;
        }
    }
    cout << cnt1 << " " << cnt2 << endl;
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