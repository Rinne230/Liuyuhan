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

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    int ans = n * m;
    vector<pll> op(q + 1);
    int cnt = 0;
    vi vis1(n + 1), vis2(m + 1);
    rep(i, 1, q){
        cin >> op[i].x >> op[i].y;
        if (op[i].x == 0 && !vis1[op[i].y]) {cnt++; vis1[op[i].y] = 1;}
    }
    sort(all(op));
    for (int i = 1; i <= n; ++i) vis1[i] = 0;
    for (int i = 1; i <= q; ++i){
        if (op[i].x == 0 && !vis1[op[i].y]) {ans -= m; vis1[op[i].y] = 1;}
        if (op[i].x == 1 && !vis2[op[i].y]) {ans -= n - cnt; vis2[op[i].y] = 1;}
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