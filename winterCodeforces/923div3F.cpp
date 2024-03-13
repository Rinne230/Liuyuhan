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

struct edges{
    int u, v, w;
}e[maxn];
vector<pll> G[maxn];
vi path;
int n, m, U, V, W, fa[maxn], vis[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v){
    fa[find(u)] = find(v);
}

bool dfs(int now){
    if (now == V) return true;
    for (auto it : G[now]){
        if (it.second < W || vis[it.first]) continue;
        vis[it.first] = 1;
        path.push_back(it.first);
        if (dfs(it.first)) return true;
        path.pop_back();
    }
    return false;
}

void solve(){
    cin >> n >> m;
    rep(i, 1, n) fa[i] = i, G[i].clear(), vis[i] = 0;
    rep(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
    path.clear();
    sort(e + 1, e + m + 1, [](edges a, edges b){
        return a.w > b.w;
    });
    rep(i, 1, m){
        auto u = e[i].u, v = e[i].v, w = e[i].w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        if (find(u) == find(v)){
            U = u, V = v, W = w;
        }else{
            merge(u, v);
        }
    }
    path.push_back(U);
    vis[U] = 1;
    dfs(U);
    cout << W << " " << path.size() << endl;
    for (auto it : path) cout << it << " ";
    cout << endl;
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