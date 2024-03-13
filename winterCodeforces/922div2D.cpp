#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
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
const ll inf64 = 2e18;

void solve(){
    int n;
    cin >> n;
    vi a(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i - 1] + a[i];
    int l = *max_element(all(a)), r = s[n];
    auto check = [&](int x){
        vi dp(n + 1, inf64);
        dp[0] = 0;
        for (int i = 1, sum = 0; i <= n; ++i){
            sum += a[i];
            if (sum <= x) dp[i] = 0;
            else break;
        }
        priority_queue<pll, vector<pll>, greater<pll>> q;
        for (int i = 1; i <= n; ++i){
            dp[i] = min(dp[i], dp[i - 1] + a[i]);
            while (q.size() && s[i] - s[q.top().second] > x) q.pop();
            if (q.size()){
                dp[i] = min(dp[i], q.top().first);
            }
            q.emplace(dp[i - 1] + a[i], i);
        }
        return dp[n] <= x;
    };
    while (l < r){
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
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