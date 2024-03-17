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

vector<pll> G[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1, u, v, w; i < n; ++i){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    int fr1 = 0, fr2 = 0;
    vector<int> dis(n + 1, inf32);
    dis[0] = 0;
    dis[1] = 0;
    function<void(int, int)> dfs1 = [&](int u, int fa){
        for (auto [v, w] : G[u]){
            if (v == fa) continue;
            dis[v] = dis[u] + w;
            if (dis[v] > dis[fr1]){
                fr1 = v;
            }
            dfs1(v, u);
        }
    };
    dfs1(1, 0);
    dis[fr1] = 0;
    function<void(int, int)> dfs2 = [&](int u, int fa){
        for (auto [v, w] : G[u]){
            if (v == fa) continue;
            dis[v] = dis[u] + w;
            if (dis[v] > dis[fr2]){
                fr2 = v;
            }
            dfs2(v, u);
        }
    };
    dfs2(fr1, 0);
    cout << dis[fr2] * 10 + dis[fr2] * (1 + dis[fr2]) / 2 << endl;
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