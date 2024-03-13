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
    int n, b, x;
    cin >> n >> b >> x;
    vl c(n + 1);
    rep(i, 1, n) cin >> c[i];
    sort(all(c));
    //x个数,d组数,默认 x >= d
    auto calc = [&](int x, int d) -> int{
        int res = (x - 1) * x / 2;
        int l = x / d;
        int r = x % d;
        res -= d * (l * (l - 1) / 2);
        res -= l * r;
        return res * b;
    };
    int mx = 0, pre = 0, st = 1;
    for (int i = 1; i <= c[n]; ++i){
        int cur = pre - (i - 1) * x;
        for (int j = st; j <= n; ++j){
            int res = calc(c[j], i);
            cur += res;
            if (i >= c[j]) st = j + 1, pre += res;
        }
        mx = max(mx, cur);
    }
    cout << mx << endl;
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