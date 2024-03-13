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
    vector<pll> cho(n + 1);
    int mx = 0;
    rep(i, 1, n){
        cin >> cho[i].x >> cho[i].y;
        mx = max({mx, cho[i].x * cho[i].y});
    }
    int l = 1, r = mx;
    auto check = [&](int len, int cnt = 0){
        rep(i, 1, n){
            int cnt1 = 0, cnt2 = 0;
            cnt1 = cho[i].x / len;
            cnt2 = cho[i].y / len;
            cnt += cnt1 * cnt2;
        }
        if (cnt >= k) return true;
        return false;
    };
    while(l < r){
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << endl;
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