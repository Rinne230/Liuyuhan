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

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

vi f(maxn);
vi inv(maxn);

void init(int n) {
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    inv[n] = qmi(f[n], mod - 2);
    for (int i = n; i; i--) {
        inv[i - 1] = inv[i] * i % mod;
    }
}

int C(int a, int b) {
    if (a < b) return 0;
    return f[a] * inv[b] % mod * inv[a - b] % mod;
}
void solve(){
    int n, m;
    cin >> n >> m;
    init(m);
    int ans = 1;
    for (int k = 1; k <= n - 3; k++) {
        ans = (ans + C(n - 3, k)) % mod;
    }
    cout << ans * C(m, n - 1) % mod * (n - 2) % mod;
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