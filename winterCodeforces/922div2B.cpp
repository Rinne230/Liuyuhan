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
    int n;
    cin >> n;
    vector<pll> p(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> p[i].x;
    }
    for (int i = 1; i <= n; ++i){
        cin >> p[i].y;
    }
    sort(all(p), [&](pll a, pll b){
        return a.x < b.x;
    });
    for (int i = 1; i <= n; ++i){
        cout << p[i].x << " \n"[i == n];
    }
    for (int i = 1; i <= n; ++i){
        cout << p[i].y << " \n"[i == n];
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