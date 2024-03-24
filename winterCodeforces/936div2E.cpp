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
const ll N = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int f[N];

int qmi(int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a){
    return qmi(a, mod - 2);
}

void init(){
    f[0] = 1;
    rep(i, 1, N - 1) f[i] = f[i - 1] * i % mod;
}

int C(int a, int b){
    return f[a] * inv(f[b]) % mod * inv(f[a - b]) % mod;
}

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vi a(m1 + 1), b(m2 + 1);
    rep(i, 1, m1) cin >> a[i];
    rep(i, 1, m2) cin >> b[i];
    if (a[1] != 1 || a[m1] != b[1] || b[m2] != n) {cout << 0 << endl; return;}
    int ans = C(n - 1, a[m1] - 1);
    int num = a[m1] - 1;
    for (int i = m1 - 1; i >= 1; --i){
        ans = (ans * C(num - 1, a[i + 1] - a[i] - 1) % mod * f[a[i + 1] - a[i] - 1]) % mod;
        num = a[i] - 1;
    }
    num = n - b[1];
    for (int i = 2; i <= m2; ++i){
        ans = (ans * C(num - 1, b[i] - b[i - 1] - 1) % mod * f[b[i] - b[i - 1] - 1]) % mod;
        num = n - b[i];
    }
    cout << ans << endl;
}

signed main(){
    ios;
    int t = 1;
    init();
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}