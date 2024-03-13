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
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int a, b, n;
    cin >> a >> b >> n;
    if (n == 1) {
        cout << 2 << endl;
        return;
    }
    int ans = 0;
    vi f(maxn);
    f[0] = 1;
    rep(i, 1, maxn - 1) f[i] = 1ll * i * f[i - 1] % mod;
    vi inv(maxn);
    inv[maxn - 1] = qmi(f[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    auto check = [&](int x){
        while (x){
            int y = x % 10;
            if (y != a && y != b) return false;
            x /= 10;
        }
        return true;
    };
    rep(i, 0, (9 * n)){
        if (!check(i)) continue;
        int y = i - b * n;
        if (y % (a - b) != 0) continue;;
        int x = y / (a - b);
        if (x < 0 || n - x < 0) continue;
        if (!x || !(n - x)) {
            ans = (ans + 1) % mod;
        }else{
            ans = (ans + 1ll * f[n] * inv[n - x] % mod * inv[x] % mod) % mod;
        }
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