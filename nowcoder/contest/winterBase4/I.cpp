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

struct Node
{
    int d;
    int x, z;
    bool operator < (const Node &a) const{
        return d > a.d;
    }
};
int n, m;
vector<pll> G[maxn];
vector<int> idx[maxn];
int d[maxn][2];
int vis[maxn][2];
priority_queue<Node> q;

void solve(){
    cin >> n >> m;
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    for (int i = 1; i <= n; ++i){
        idx[i].resize(G[i].size());
        for (int j = 0; j < idx[i].size(); ++j){
            idx[i][j] = j;
        }
        sort(idx[i].begin(), idx[i].end(), [&](int a, int b){
            return G[i][a].y < G[i][b].y;
        });
        while (idx[i].size() > 2){
            idx[i].pop_back();
        }
    }
    memset(d, 0x3f, sizeof d);
    auto update = [&](int y, int z, int v){
        if (d[y][z] > v){
            d[y][z] = v;
            q.push({d[y][z], y, z});
        }
    };
    update(1, 0, 0);
    while (!q.empty()){
        auto[dd, x, z] = q.top();
        q.pop();
        if (vis[x][z]){
            continue;
        }
        vis[x][z] = 1;
        if (z == 0){
            for (int i = 0; i < G[x].size(); ++i){
                auto [y, w] = G[x][i];
                update(y, 0, d[x][z] + w);
                update(y, 1, d[x][z]);
            }
        }else{
            if (idx[x].size() == 2){
                for (int i = 0; i < G[x].size(); ++i){
                    auto [y, w] = G[x][i];
                    if (i != idx[x][0]){
                        update(y, 0, d[x][z] + w + G[x][idx[x][0]].y);
                        update(y, 1, d[x][z] + G[x][idx[x][0]].y);  
                    }else{
                        update(y, 0, d[x][z] + w + G[x][idx[x][1]].y);
                        update(y, 1, d[x][z] + G[x][idx[x][1]].y);
                    }
                }
            }
        }
    }
    int ans = d[n][0];
    if (idx[n].size() >= 1){
        ans = min(ans, d[n][1] + G[n][idx[n][0]].y);
    }
    if (ans > 1e18) ans = -1;
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