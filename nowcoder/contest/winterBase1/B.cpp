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
    int n;
    set<pll> lct;
    ll x, y, l = 2, r = 2;
    cin >> n;
    lct.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        lct.insert({ x,y });
        if (y >= 0) r = 1;
        if (y <= 0) l = 1;
    }
    ll ans = 3;
    if (lct.find({ 1,-1 })!=lct.end()) --ans;
    if (lct.find({ 1,1 })!=lct.end()) --ans;
    if (lct.find({ 2,0 })!=lct.end()) --ans;
    for (auto i : lct) {
        x = i.first, y = i.second;
        for (int j = -1; j <= 1; ++j) {
            if (lct.find({ x ^ 3, y + j }) != lct.end()) {
                if (y > 0) r = 0;
                if (y < 0) l = 0;
            }
        }
    }
    cout << min(ans, l + r) << "\n";
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