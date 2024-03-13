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
    map<int, int> ok;
    int n, m, l;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    cin >> m;
    vi b(m + 1);
    rep(i, 1, m) cin >> b[i];
    cin >> l;
    vi c(l + 1);
    rep(i, 1, l) cin >> c[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 1; k <= l; ++k)
                ok[a[i] + b[j] + c[k]]++;
    int q;
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        if (ok[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
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