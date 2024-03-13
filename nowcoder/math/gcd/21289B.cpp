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
const ll maxn = 3e6 + 10;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int s[maxn], sv[maxn];
int inv[maxn];

int qpow(int a, int b, int mod){
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;

}
void solve(){
    int n, p;
    cin >> n >> p;
    s[0] = 1;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] * i % p;
    }
    sv[n] = qpow(s[n], p - 2, p);
    for (int i = n; i >= 1; --i) {
        sv[i - 1] = sv[i] * i % p;
    }
    for (int i = 1; i <= n; ++i){
        inv[i] = sv[i] * s[i - 1] % p;
    }
    for (int i = 1; i <= n; ++i){
        cout << inv[i] << endl;
    }
    
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