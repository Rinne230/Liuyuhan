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
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vector<vi> G(n + 1);
    rep(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int k;
    cin >> k;
    vi a(k + 1), b(k + 1), tag(n + 1);
    rep(i, 1, k){
        cin >> a[i] >> b[i];
        tag[a[i]] ^= (1 << (i - 1));
        tag[b[i]] ^= (1 << (i - 1));
    }
    vi p, dp(1 << k, inf32);
    function<void(int, int)> dfs = [&] (int u, int fa){
        for(auto v : G[u]){
            if(v == fa) continue;
            dfs(v, u);
            tag[u] ^= tag[v];
        }
        p.push_back(tag[u]);
    };
    dfs(1, 0);
    sort(p.begin(), p.end());  
    p.erase(unique(p.begin(), p.end()), p.end());
    dp[0] = 0;
    for (int i = 0; i < (1 << k); ++i){
        for (int j = 0; j < p.size(); ++j){
            dp[i | p[j]] = min(dp[i | p[j]], dp[i] + 1);
        }
    }
    cout << dp[(1 << k) - 1] << endl;
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