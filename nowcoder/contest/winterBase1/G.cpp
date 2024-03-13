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
    int n, m;
    cin >> n >> m;
    vector<pll> c(n + 1);
    rep(i, 1, n){
        cin >> c[i].x >> c[i].y;
    }
    sort(all(c), [&](pll a, pll b){
        return a.x < b.x;
    });
    int sum = 0, delsum = 0;
    int ans = 0;
    rep(i, 1, n){
        sum = c[i].x;
        delsum += c[i].y;
        if (sum - delsum <= m){
            ans = m + delsum;
        }
    }
    cout << max(m, ans) << endl;
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