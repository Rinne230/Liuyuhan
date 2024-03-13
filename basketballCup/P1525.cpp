#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin(), a.end()
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
    int n, m;
    cin >> n >> m;
    vi f(n + 1), emy(n + 1);
    for (int i = 1; i <= n; ++i) f[i] = i;
    function<int(int)> find = [&](int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    };
    vector<tll> p;
    for (int i = 1; i <= m; ++i) {
        int z, x, y;
        cin >> x >> y >> z;
        p.push_back({z, x, y});
    }
    sort(all(p), [](tll a, tll b) {
        return get<0>(a) > get<0>(b);
    });
    for (int i = 0; i < m; ++i){
        auto [z, x, y] = p[i];
        int fx = find(x), fy = find(y);
        if (fx == fy) {cout << z << endl; return;}
        if (!emy[x]) emy[x] = y;
        else f[find(emy[x])] = find(y);
        if (!emy[y]) emy[y] = x;
        else f[find(emy[y])] = find(x);
    }
    cout << 0 << endl;
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