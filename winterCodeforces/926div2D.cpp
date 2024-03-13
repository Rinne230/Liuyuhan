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
    vector f(n + 1, vi(3, 0));
    rep(i, 1 ,n - 1){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int fa){
        f[u][0] = f[u][1] = 1;
        f[u][2] = 0;
        int mul = 1, sum = 0;
        for (auto v : G[u]){
            if (v == fa) continue;
            dfs(v, u);
            mul = (mul * (f[v][0] + f[v][1])) % mod;
            sum = ((sum + f[v][1]) % mod + f[v][2]) % mod;
        }
        f[u][1] = mul;
        f[u][2] = sum;
    };
    dfs(1, 1);
    cout << (f[1][0] + f[1][1] + f[1][2]) % mod << endl;
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