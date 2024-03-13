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
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, 0, n - 1) cin >> b[i];
    rep(i, 0, n - 1) cin >> a[i];
    sort(all(b));
    int ans = 1e9, x, y;
    for (int i = 0; i < n; ++i){
        int k = lower_bound(all(b), a[i]) - b.begin();
        if (k != n && ans > b[k] - a[i]) {
            ans = b[k] - a[i];
            x = i, y = k;
        }
        if (k != 0 && ans > a[i] - b[k - 1]) {
            ans = a[i] - b[k - 1];
            x = i, y = k - 1;
        }
    }
    swap(b[x], b[y]);
    for (int i = 0; i < n; ++i) cout << b[i] << " \n"[i == n - 1];
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