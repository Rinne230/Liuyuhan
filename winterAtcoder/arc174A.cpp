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
    int n, c;
    cin >> n >> c;
    vi a(n + 1);
    int ans = 0;
    rep(i, 1, n){
        cin >> a[i];
        ans += a[i];
    }
    int mx = 0, tmx = 0;
    int mn = 0, tmn = 0;
    for (int i = 1; i <= n; ++i){
        tmx = max(a[i], a[i] + tmx);
        mx = max(mx, tmx);
        tmn = min(a[i], a[i] + tmn);
        mn = min(mn, tmn);
    }
    // cout << ans << endl;
    // cout << mx << " " << mn << endl;
    ans = max(ans + (c - 1) * mx, ans + (c - 1) * mn );
    cout << ans << endl;
}

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}