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
    vi a(6), p(6);
    int sum = 0, tot = 0;
    for (int i = 1; i <= 5; ++i){
        cin >> a[i];
        sum += a[i];
        tot += i * a[i];
    }
    int ans = 0;
    for (int i = 1; i <= 5; ++i) cin >> p[i];
    int need = 3 * sum - tot;
    if (need <= 0){
        cout << 0 << endl;
        return;
    }
    int res = inf64;
    res = min(res, need * p[4]);
    res = min(res, p[4] + (need) / 2 * p[5]);
    res = min(res, (need + 1) / 2 * p[5]);
    cout << res << endl;
}

signed main(){
    lyh;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}