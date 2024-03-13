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
    vi a(n + 1);
    vi d(m + 1), s(m + 1), t(m + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> d[i] >> s[i] >> t[i];
    int l = 0, r = m;
    auto check = [&](int x)->bool{
        vector<int> b(n + 2);
        rep(i, 1, x){
            b[s[i]] += d[i];
            b[t[i] + 1] -= d[i];
        }
        rep(i, 1, n) b[i] += b[i - 1];
        rep(i, 1, n) if(b[i] > a[i]) return false;
        return true;
    };
    if (!check(m)){
        cout << -1 << endl;
        while (l < r){
            int mid = l + r >> 1;
            if (check(mid)) l = mid + 1;
            else r = mid;
        }
        cout << l << endl;
    }else{
        cout << 0 << endl;
    }
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