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
    cin >> n;
    vl a(n + 1), d(n + 1), mn(n + 1, 0); 
    rep(i, 1, n) cin >> a[i], d[i] = a[i] - a[i - 1];
    rep(i, 1, n) mn[i] = min(mn[i - 1], d[i]);
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    if (n % 2 == 0){
        cout << "YES" << endl;
        return;
    }
    bool ok = true;
    for (int i = 1; i <= n - 1; ++i) 
        if (a[i] > a[i + 1]) ok = false;
    if (ok){
        cout << "YES" << endl;
        return;
    }
    stack<pll> dex;
    for (int i = 3; i <= n; i += 2){
        dex.push({i, d[i]});
    }
    int sum = 0;
    while (!dex.empty()){
        auto [i, x] = dex.top();
        //cout << "check : " << i << " " << x << endl;
        dex.pop();
        if (x + sum < 0){
            cout << "NO" << endl;
            return;
        }
        sum += max(0ll, (x + sum) / (i - 1));
        if (a[i - 1] + sum < a[i - 2]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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