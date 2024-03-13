#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
//#define int ll
#define rep(i, j, k) for(int i = (j); i < (k); i++)
#define per(i, j ,k) for(int i = (j); i > (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std; 
typedef long long ll;
const ll N = 5e3 + 10;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

vector<vi> f(N, vi(N, 0));
vector<vi> g(2, vi(N, 0));
void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    vi l(n);
    rep(i, 0, n) cin >> l[i];
    f[0][0] = 1;
    rep(i, 1, N) {
        rep(j, 1, i + 1) {
            f[i][j] = (1ll * f[i - 1][j] * (j - 1) % p + f[i - 1][j - 1]) % p;
        }
    }
    rep(j, 1, min(l[0], m) + 1) g[0][j] = f[l[0]][j];
    vi F(N);
    F[0] = 1;
    rep(i, 1, N) {
        F[i] = 1ll * F[i - 1] * i % p;
    }
    vi t(m + 1);
    t[0] = 1;
    rep(i, 1, m + 1) {
        t[i] = (1ll * t[i - 1] * (m - i + 1)) % p;
    }
    vi s(n);
    rep(j, 1, min(l[0], m) + 1) {
        s[0] = (s[0] + 1ll * g[0][j] * t[j] % p) % p;
    }
    rep(k, 1, n) {
        int c = k & 1;
        rep(j, 1, min(l[k], m) + 1) {
            int cur = g[!c][j];
            if (j > l[k - 1]) cur = 0;
            g[c][j] = 1ll * f[l[k]][j] * (s[k - 1] - 1ll * cur * F[j] % p) % p;
            if (g[c][j] < 0) g[c][j] += p;
        }
        rep(j, 1, min(l[k], m) + 1) {
            s[k] = (s[k] + 1ll * g[c][j] * t[j] % p) % p;
        }
        if (s[k] < 0) s[k] += p;
    }
    cout << s[n - 1] << '\n';
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