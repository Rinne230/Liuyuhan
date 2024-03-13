#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 4e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

vector<int> G[maxn];

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1), f(n + 1);
    function<int(int)> find = [&](int x){
        if (x == f[x]) return x;
        return f[x] = find(f[x]);
    };
    rep(i, 1, n) f[i] = i;
    rep(i, 1, m){
        int u, v;
        cin >> u >> v;
        u++, v++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int k;
    cin >> k;
    stack<int> ks;
    for (int i = 1; i <= k; ++i){
        int x;
        cin >> x;
        x++;
        ks.push(x);
        vis[x] = 1;
    }
    int num = n - k;
    for (int i = 1; i <= n; ++i){
        if (!vis[i]){
            for (auto j : G[i]){
                if (!vis[j]){
                    int fx = find(i), fy = find(j);
                    if (fx != fy){
                        f[fx] = fy;
                        num--;
                    }
                }
            }
        }
    }
    stack<int> ans;
    ans.push(num);
    while (!ks.empty()){
        int x = ks.top();
        vis[x] = 0;
        ks.pop();
        num++;
        for (auto i : G[x]){
            if (!vis[i]){
                int fx = find(x), fy = find(i);
                if (fx != fy){
                    f[fx] = fy;
                    num--;
                }
            }
        }
        ans.push(num);
    }
    while (!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
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