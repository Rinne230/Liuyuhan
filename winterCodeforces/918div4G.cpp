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
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> G(n);
    for (int i = 0, u, v, w; i < m; ++i){
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vi s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<vector<int>> vis(n, vector<int>(1001));
    vector<vector<int>> dis(n, vector<int>(1001, 1E18));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
    q.push({dis[0][s[0]] = 0, 0, s[0]});
    int ans = 1e18;
    while (!q.empty()){
        auto [res, cur, v] = q.top();
        q.pop();
        if (cur == n - 1) {
            ans = min(ans, res);
            continue;
        }
        if (!vis[cur][v]){
            vis[cur][v] = 1;
            for (auto &[nex, w] : G[cur]){
                if (dis[nex][v] > res + 1ll * v * w){
                    dis[nex][v] = res + 1ll * v * w;
                    q.push({dis[nex][v], nex, min(v, 1ll * s[nex])});
                }
            }
        }
    }
    cout << ans << endl;
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