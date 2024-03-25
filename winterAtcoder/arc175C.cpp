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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vi L(n), R(n);
    rep(i, 0, n - 1){
        cin >> L[i] >> R[i];
    }
    vi l(n), r(n);
    l.back() = L.back();
    r.back() = R.back();
    for (int i = n - 2; i >= 0; --i){
        if (R[i] < l[i + 1]){
            l[i] = r[i] = R[i];
        }else if (L[i] > r[i + 1]){
            l[i] = r[i] = L[i];
        }else{
            l[i] = max(L[i], l[i + 1]);
            r[i] = min(R[i], r[i + 1]);
        }
    }
    vi a(n);
    a.front() = l.front();
    for (int i = 1; i < n; ++i) a[i] = max(min(a[i - 1], r[i]), L[i]);
    for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
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