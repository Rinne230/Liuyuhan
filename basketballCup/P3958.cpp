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
    int n, h, r;
    cin >> n >> h >> r;
    vi f(n + 1);
    for (int i = 1; i <= n; ++i) f[i] = i;
    vector<tll> pos(n + 1);
    vi ups, downs;
    for (int i = 1; i <= n; ++i) {
        auto &[x, y, z] = pos[i];
        cin >> x >> y >> z;
        if (z - r <= 0) downs.push_back(i);
        if (z + r >= h) ups.push_back(i);
    }
    function<int(int)> find = [&](int x){
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    };
    auto dis = [&](int x, int y){
        auto &[x1, y1, z1] = pos[x];
        auto &[x2, y2, z2] = pos[y];
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
    };
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            if (dis(i, j) <= 4 * r * r) f[find(i)] = find(j);
        }
    }
    for (auto i : ups){
        for (auto j : downs){
            if (find(i) == find(j)){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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