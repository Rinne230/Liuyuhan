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
    vi a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i] >> b[i];
    auto check = [&](int x) -> bool{
        int cnt = 0;
        for (int i = 1; i <= n; ++i){
            if (a[i] > x)
                cnt += (a[i] - x + b[i] - 1) / b[i];
        }
        return cnt <= m;
    };
    int l = 0, r = 1e6;
    while (l < r){
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    int final = l;
    int ans = 0, cnt = 0;
    auto sum = [&](int r, int n, int d) -> int{
        int l = r - (n - 1) * d;
        return 1ll * (l + r) * n / 2;
    };
    for (int i = 1; i <= n; ++i){
        if (a[i] > final){
            int t = (a[i] - final + b[i] - 1) / b[i];
            cnt += t;
            ans += sum(a[i], t, b[i]);
        }
    }
    ans += (m - cnt) * final;
    cout << ans << endl;
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