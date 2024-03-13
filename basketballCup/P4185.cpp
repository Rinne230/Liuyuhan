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
const ll maxn = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct Qnode{
    int k, v, id;
    bool operator()(const Qnode &a, const Qnode &b){
        return a.k > b.k;
    }
}q[maxn];

struct edge{
    int u, v, w;
    bool operator()(const edge &a, const edge &b){
        return a.w > b.w;
    }
}e[maxn];

int f[maxn], sz[maxn], ans[maxn];

int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        f[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].k >> q[i].v;
        q[i].id = i;
    }
    sort(e + 1, e + n, edge());
    sort(q + 1, q + m + 1, Qnode());
    int tot = 1;
    for (int i = 1; i <= m; ++i){
        while (q[i].k <= e[tot].w){
            int fu = find(e[tot].u), fv = find(e[tot].v);
            sz[fv] += sz[fu];
            f[fu] = fv;
            ++tot;
        }
        ans[q[i].id] = sz[find(q[i].v)];
    }
    for (int i = 1; i <= m; ++i){
        cout << ans[i] - 1 << endl;
    }
}

signed main(){
    ios;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}