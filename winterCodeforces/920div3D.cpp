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
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n + 1), b(m + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    sort(all(b), [&](int x, int y){
        return x > y;
    });
    sort(all(a));
    int ans = 0, fin = 0;
    int l = n, r = m + 1;
    for (int i = 1; i <= n; ++i){
        ans += abs(a[i] - b[i]);
    }
    fin = ans;
    while (l >= 1){
        ans -= abs(a[l] - b[l]);
        ans += abs(a[l] - b[--r]);
        l--;
        fin = max(ans, fin);
    }
    cout << fin << endl;
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