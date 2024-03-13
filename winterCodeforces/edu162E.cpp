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
    map<int, int> mp[n + 1];
    vi cnt(n + 1, 0);
    int ans = 0;
    vi col(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> col[i], cnt[col[i]]++;
    vector<vi> g(n + 1);
    for(int i = 1, u, v; i <= n - 1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto merge = [&](int i, int j){
		if(mp[i].size() < mp[j].size()) {
			swap(mp[i], mp[j]);
		}
		for(auto [x, y] : mp[j]) {
			mp[i][x] += y;
		}
	};

    function<void(int, int)> dfs = [&](int u, int fa){
        mp[u][col[u]]++;
        for (auto v : g[u]){
            if (v == fa) continue;
            dfs(v, u);
            ans += mp[v][col[u]] * (mp[v][col[u]] - 1) / 2;
            merge(u, v);
        }
        ans += mp[u][col[u]] - 1;
        mp[u][col[u]] = 1;
    };
    dfs(1, 1);
    for(auto [x, y] : mp[1]) {
		ans += (ll)y * (y - 1) / 2;
	}
	cout << ans << '\n';
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