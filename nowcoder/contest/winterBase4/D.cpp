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
    int n, sum = 0, ji = 0;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n) {
        cin >> a[i], sum += a[i];
        if (a[i] & 1) ji++;
    }
    int tot = sum / n;
    int ans = 0;
    rep(i, 1, tot){
        if ((i % 2 == 0) && (ji & 1)){
            continue;
        }
        if (sum % i == 0) ans++;
    }
    if (n == 1){
        cout << 1 << endl;
        return;
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