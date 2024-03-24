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

int vis[N], match[N];
vi g[N];

bool dfs(int u, int tag){
    if (vis[u] == tag) return false;
    vis[u] = tag;
    for (auto v : g[u]){
        if (!match[v] || dfs(match[v], tag)){
            match[v] = u;
            return true;
        }
    }
}

void solve(){
    int n, m, t;
    cin >> n >> m >> t;
    
    while (t--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

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