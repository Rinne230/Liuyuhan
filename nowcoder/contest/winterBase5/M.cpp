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
    vi a(n + 1), b(n + 1), d(n + 1), idx(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i], idx[b[i]] = i;
    for (int i = 1; i <= n; ++i){
        d[i] = idx[a[i]];
    }
    if (n == 1){
        cout << -1 << endl;
        return;
    }
    if (n == 2){
        if (d[1] == 1 && d[2] == 2){
            cout << -1 << endl;
            return;
        }else{
            cout << 1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; ++i){
        if (d[i] == i && i != 1 && i != n){
            cout << 1 << endl;
            return;
        }
        if (abs(d[i] - i) == 1){
            cout << 1 << endl;
            return;
        }
    }
    cout << 2 << endl;
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