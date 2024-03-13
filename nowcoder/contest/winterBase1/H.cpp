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
    int ans = 0;
    cin >> n >> m;
    vi v(n + 1), w(n + 1);
    rep(i, 1, n) {
        cin >> v[i] >> w[i];
        if ((w[i] | m) == m) ans += v[i];
    }
    for (int i = 0; (1 << i) <= m; ++i){
        int c = 1 << i;
        if (c & m){
            int sum = 0;
            rep(j, 1, n){
                if (w[j] < c) sum += v[j];
                else if ((w[j] & c) == 0){
                    int tmp = (w[j] >> i) | (m >> i);
                    if (tmp == (m >> i)) sum += v[j];
                }
            }
            ans = max(ans, sum);
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