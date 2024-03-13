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
    vi a(n + 1), cnt(n + 1, 0);
    rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
    int mex = -1;
    for (int i = 0; i <= n - 1; ++i){
        if (cnt[i] == 0) {
            mex = i;
            break;
        }
    }
    if (mex == -1) {cout << -1 << endl; return;}
    int ans = 0;
    int lst = 1;
    map<int, int> mp;
    vector<pll> p;
    for (int i = 1; i <= n; ++i){
        if (a[i] < mex){
            mp[a[i]]++;
        }
        if (mp.size() == mex){
            ans++;
            p.push_back({lst, i});
            lst = i + 1;
            mp.clear();
        }
    } 
    if (ans <= 1) {cout << -1 << endl; return;}
    cout << ans << endl;
    int idx = 0;
    for (auto [l, r] : p){
        idx++;
        if (idx == ans) r = n;
        cout << l << " " << r << endl;
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