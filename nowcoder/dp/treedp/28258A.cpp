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

int n;
void solve(){
    vector<vi> G(n + 1);
    for (int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u); 
    }
    vi sz(n + 1);
    int id = inf32, mn = inf32;
    function<void(int, int)> dfs = [&](int u, int fa){
        sz[u] = 1;
        for (auto v : G[u]){
            if (v == fa) continue;
            dfs(v, u);
            sz[u] += sz[v];
            int mx = max(sz[u], n - sz[u]);
            if (mx <= mn){
                mn = mx;
                id = min(u, id);
            }
        }
   };
   dfs(0, 0);
   cout << id + 1 << " " << mn - 1 << endl;
}

signed main(){
    ios;
    int t = 1;
    //cin >> t;
    while(cin >> n){
        solve();
    }
    return 0;
}