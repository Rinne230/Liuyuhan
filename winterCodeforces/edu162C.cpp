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
    int n, q;
    cin >> n >> q;
    vi a(n + 1), prez(n + 1), sum(n + 1);
    rep(i, 1, n) cin >> a[i], prez[i] = prez[i - 1] + (a[i] == 1), sum[i] = sum[i - 1] + a[i];
    while (q--){
        int l, r;
        cin >> l >> r;
        if (l == r) {cout << "NO" << endl; continue;}
        int cnt = prez[r] - prez[l - 1];
        
        int s = sum[r] - sum[l - 1];
        if (s - (r - l + 1) >= cnt) cout << "YES" << endl;
        else cout << "NO" << endl;
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