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

int notprime[maxn], prime[maxn], cnt;
void getprime(int n){
    notprime[1] = 1;
    rep(i, 2, n - 1){
        if(!notprime[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] < n; j++){
            notprime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

void solve(){
    int l, r;
    cin >> l >> r;
    getprime(r);
    for (int i = 1; i <= cnt; ++i){
        for (int j = 1; j <= cnt; ++j){
            if (i == j) continue;
            for (int k = 1; k <= cnt; ++k){
                if (i == k || j == k) continue;
                if (prime[i] * prime[j] * prime[k] >= l && prime[i] * prime[j] * prime[k] <= r){
                    cout << prime[i] * prime[j] * prime[k] << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
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