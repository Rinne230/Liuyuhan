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
    vi a(n + 1), sum(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int d = 1; d <= n; ++d){
        if (n % d == 0){
            int mx = 0, mn = 1e18;
            for (int j = d; j <= n; j += d){
                int tmp = sum[j] - sum[j - d];
                mx = max(tmp, mx);
                mn = min(tmp, mn);
            }
            ans = max(mx - mn, ans);
        }
    }
    cout << ans << endl;
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