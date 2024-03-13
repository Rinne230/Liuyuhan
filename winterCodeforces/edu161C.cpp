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
    int n, q;
    cin >> n;
    vi a(n + 1);
    vi dis1(n + 1), dis2(n + 1);
    vi pre(n + 1), suf(n + 1);
    dis1[1] = dis2[n] = 1;
    rep(i, 1, n) cin >> a[i];
    for (int i = 2; i <= n - 1; ++i){
        if (a[i + 1] - a[i] < a[i] - a[i - 1]) dis1[i] = 1;
        else dis1[i] = a[i + 1] - a[i];
    }
    for (int i = n - 1; i >= 2; --i){
        if (a[i] - a[i - 1] < a[i + 1] - a[i]) dis2[i] = 1;
        else dis2[i] = a[i] - a[i - 1];
    }
    for (int i = 2; i <= n; ++i){
        pre[i] = pre[i - 1] + dis1[i - 1];
    }
    for (int i = n - 1; i >= 1; --i){
        suf[i] = suf[i + 1] + dis2[i + 1];
    }
    cin >> q;
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        if (l < r) cout << pre[r] - pre[l] << endl;
        else cout << suf[r] - suf[l] << endl;
    }
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