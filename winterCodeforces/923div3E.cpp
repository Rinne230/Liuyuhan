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
    int n, k;
    cin >> n >> k;
    int l = 1, r = n;
    int idx = 1;
    vi a(n + 1);
    while (1){
        if (l > r) break;
        for (int i = idx; i <= n; i += k){
            a[i] = r--;
        }
        idx++;
        if (l > r) break;
        for (int i = idx; i <= n; i += k){
            a[i] = l++;
        }
        idx++;
    }
    rep(i, 1, n) cout << a[i] << " \n"[i == n];
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