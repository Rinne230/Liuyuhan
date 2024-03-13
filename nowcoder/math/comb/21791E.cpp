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
const ll maxn = 5e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int C[maxn][maxn];
vi f(maxn);

void init(){
    C[0][0] = 1;
    rep(i, 1, maxn - 1) {
        C[i][0] = 1;
        rep(j, 1, i) {
            C[i][j] = (0ll + C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
    f[0] = 1;
    rep(i, 1, maxn - 1) f[i] = 1ll * i * f[i - 1] % mod;
}

int calc(int a, int b){
    int res = 0;
    for (int i = 0; i <= min(a, b); ++i){
        res = (res + 1ll * C[a][i] * C[b][i] % mod * f[i] % mod) % mod;
    }
    return res;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1;
    ans = (ans * calc(a, b)) % mod;
    ans = (ans * calc(a, c)) % mod;
    ans = (ans * calc(b, c)) % mod;
    cout << ans << endl;
}

signed main(){
    ios;
    init();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}