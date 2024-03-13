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
    int n, f, a, b, sum = 0;
    cin >> n >> f >> a >> b;
    vi m(n + 1);
    for (int i = 1; i <= n; ++i) cin >> m[i];
    for (int i = 1; i <= n; ++i){
        int tmp = m[i] - m[i - 1];
        sum += min(tmp * a, b);
    }
    if (sum < f) cout << "YES" << endl;
    else cout << "NO" << endl;
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