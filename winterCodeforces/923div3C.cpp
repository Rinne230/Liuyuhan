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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1), b(m + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    vi visa(k + 1), visb(k + 1);
    for (int i = 1; i <= n; ++i){
        if (a[i] > k) continue;
        visa[a[i]] = 1;
    }
    for (int i = 1; i <= m; ++i){
        if (b[i] > k) continue;
        visb[b[i]] = 1;
    }
    bool ok = 1;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= k; ++i){
        if (visa[i] && !visb[i]) cnt1++;
        if (visb[i] && !visa[i]) cnt2++;
        if (!visa[i] && !visb[i]) {
            cout << "No" << endl;
            return;
        }
    }
    if (cnt1 > k / 2 || cnt2 > k / 2) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    
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