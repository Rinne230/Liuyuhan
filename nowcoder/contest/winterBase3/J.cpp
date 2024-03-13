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
typedef long long ll;
typedef long double db;
const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

vi G[maxn];

int qpow(int a, int b){
    int ans = 1;
    while (b){
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vi maleans(n + 1, 1), femaleans(m + 1, 1);
    while (k--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v + n].push_back(u);
    }
    cout << "modint" << endl;
    for (int i = 1; i <= n; ++i){
        for (auto u : G[i]){
            int num = G[i].size();
            femaleans[u] = femaleans[u] * (num - 1) % mod * qpow(num, mod - 2) % mod;
        }
    }
    for (int i = n + 1; i <= n + m; ++i){
        for (auto u : G[i]){
            int num = G[i].size();
            maleans[u] = maleans[u] * (num - 1) % mod * qpow(num, mod - 2) % mod;
        }
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; ++i){
        ans1 = (ans1 + (1 - maleans[i] + mod) % mod) % mod;
    }
    for (int i = 1; i <= m; ++i){
        ans2 = (ans2 + (1 - femaleans[i] + mod) % mod) % mod;
    }
    cout << ans1 << " " << ans2 << endl;
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