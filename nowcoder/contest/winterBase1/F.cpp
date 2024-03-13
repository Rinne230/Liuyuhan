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
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int fac[maxn];

void init(){
    fac[0] = 1;
    rep(i, 1, maxn - 1) fac[i] = fac[i - 1] * i % mod;
}

int qmi(int a, int b){
    int res = 1;
    while(b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x){
    return qmi(x, mod - 2);
}

int C(int a, int b){
    return fac[a] * inv(fac[b]) % mod * inv(fac[a - b]) % mod;
}

int stirling(int n, int m){
    int ans = 0;
    rep(i, 0, m){
        int tmp;
        if (i % 2 == 0) tmp = 1;
        else tmp = -1;
        ans = (ans + tmp * C(m, i) * qmi(m - i, n) % mod + mod) % mod;
    }
    ans = ans * inv(fac[m]) % mod;
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    init();
    cout << stirling(n, m) << endl;
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