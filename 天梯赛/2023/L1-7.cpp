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
    int a, b, n;
    cin >> a >> b >> n;
    int ans1, ans2;
    int mn = inf64;
    for (int i = 1; i < n; ++i){
        int x1 = i, x2 = n - i;
        if (a % x1 == 0 && b % x2 == 0){
            int y1 = a / x1, y2 = b / x2;
            if (y1 == 1 || y2 == 1) continue;
            if (abs(y1 - y2) < mn){
                mn = abs(y1 - y2);
                ans1 = x1, ans2 = x2;
            }
        }
    }
    if (mn == inf64){
        cout << "No Solution" << endl;
        return;
    }
    cout << ans1 << ' ' << ans2 << endl;
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