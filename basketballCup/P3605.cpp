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
const ll N = 1e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct BIT{
    int tr[N];
    int lowbit(int x){return x & -x;}
    void add(int x, int y){
        for(; x < N; x += lowbit(x)) tr[x] += y;
    }
    int query(int x){
        int res = 0;
        for(; x; x -= lowbit(x)) res += tr[x];
        return res;
    }
}tr;

vi G[N];

void solve(){
    int n;
    cin >> n;
    vi p(n + 1);
    rep(i, 1, n) cin >> p[i];
    auto c = p;
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    rep(i, 1, n) p[i] = lower_bound(all(c), p[i]) - c.begin();
    vi ans(n + 1);
    for (int i = 2; i <= n; ++i){
        int fa;
        cin >> fa;
        G[fa].push_back(i);
    }    
    function<void(int)> dfs = [&](int u){
        ans[u] -= tr.query(n) - tr.query(p[u]);
        for (auto v : G[u]) dfs(v);
        ans[u] += tr.query(n) - tr.query(p[u]);
        tr.add(p[u], 1);
    };
    dfs(1);
    rep(i, 1, n) cout << ans[i] << endl;
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