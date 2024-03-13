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
    int n, m;
    cin >> n >> m;
    int ans = inf64;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<pll> q;
    int u, v;
    rep(i, 1, m){
        cin >> u >> v;
        if (u > v) swap(u, v);
        q.push_back({u, v});
    }
    function<void(vi, int)> dfs = [&](vi a, int idx){
        if (idx == m){
            int cnt = 0;
            for (int i = 1; i <= n; ++i) if (a[i] > a[1]) cnt++;
            ans = min(ans, cnt);
            return;
        }
        vi aa = a, ab = a, ac = a;
        aa[q[idx].first] += 3;
        dfs(aa, idx + 1);
        ab[q[idx].second] += 3;
        dfs(ab, idx + 1);
        ac[q[idx].first]++, ac[q[idx].second]++;
        dfs(ac, idx + 1);
    };
    dfs(a, 0);
    cout << ans + 1<<endl;
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