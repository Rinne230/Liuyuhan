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
    int n, ans = 0;
    cin >> n;
    vi a(n + 1), b(n + 1), cost(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 2; i <= n; ++i) {
        cin >> cost[i];
        cost[i] += cost[i - 1];
    }
    int T;
    cin >> T;
    for (int i = 1; i <= n; ++i){
        int tmp = T - cost[i];
        priority_queue<pll> q;
        for (int j = 1; j <= i; ++j){
            q.push({a[j], j});
        }
        int sum = 0;
        while (q.size() && tmp > 0){
            auto [val, idx] = q.top();
            q.pop();
            sum += val;
            tmp--;
            val -= b[idx];
            if (val > 0) q.push({val, idx});
        }
        ans = max(ans, sum);
    }
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