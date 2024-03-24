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
int dis[N];
bool vis[N];
vector<int> G[N];
void solve(){
    int n;
    cin >> n;
    
    for (int i = 1, k; i <= n; ++i){
        cin >> k;
        for (int j = 1; j <= k; ++j){
            int x;
            cin >> x;
            vis[x] = 1;
            G[i].push_back(x);
        }
    }

    function<void(int, int)> dfs = [&](int u, int fa){
        dis[u] = dis[fa] + 1;
        vis[u] = 1;
        for (auto v : G[u]){
            if (v == fa) continue;
            if (vis[v]) continue;
            if (v > n) continue;
            dfs(v, u);
        }
    };
    for (int i = 1; i <= n; ++i){
        if (!vis[i]){
            memset(vis, 0, sizeof(vis));
            dfs(i, 0);
            break;
        }
    }

    int mx = 0, ans = 1;
    for (int i = 1; i <= n; ++i){
        if (dis[i] > mx){
            mx = dis[i];
            ans = i;
        }
    }
    cout << ans << endl;
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