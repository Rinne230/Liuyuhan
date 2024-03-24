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


void solve(){
    int n;
    cin >> n;
    vector<vi> G(n + 1);
    for (int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vi fa(n + 1);
    auto find = [&](int u){
        vi dis(n + 1, -1);
        fa[u] = -1;
        dis[u] = 0;
        queue<int> q;
        q.push(u);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (auto v : G[u]){
                if (dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    fa[v] = u;
                    q.push(v);
                }
            }
        }
        return max_element(all(dis)) - dis.begin();
    };
    int u = find(1);

    int v = find(u);
    vi pos;
    for (int i = v; i != -1; i = fa[i]){
        pos.push_back(i);
    }
    int num = pos.size();
    vector<pll> ans;
    if (num & 1){
        int p = pos[num / 2];
        for (int i = 0; i <= num / 2; ++i){
            ans.push_back({p, i});
        }
    }else{
        int p1 = pos[num / 2];
        int p2 = pos[num / 2 - 1];
        for (int i = 1; i <= num / 2; i += 2){
            ans.push_back({p1, i});
            ans.push_back({p2, i});
        }
    }
    cout << ans.size() << endl;
    for (auto [v, d] : ans){
        cout << v << " " << d << endl;
    }
}

signed main(){
    lyh;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}