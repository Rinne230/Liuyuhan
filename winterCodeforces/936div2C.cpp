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

void solve(){
    int n, k;
    cin >> n >> k;
    vector G(n + 1, vector<int>());
    vi sz(n + 1);
    int l = 1, r = n;
    rep(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto check = [&](int x){
        int cnt = 0;
        function<void(int, int)> dfs = [&](int u, int fa){
            sz[u] = 1;
            for (auto v : G[u]){
                if (v == fa) continue;
                dfs(v, u);
                sz[u] += sz[v];
            }
            if (sz[u] >= x){
                sz[u] = 0;
                cnt++;
            }
        };
        dfs(1, 0);
        return cnt > k;
    };
    while (l < r){
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << endl;

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