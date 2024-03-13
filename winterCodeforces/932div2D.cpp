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
    int n, c;
    cin >> n >> c;
    int tot = (c + 1) * (c + 2) / 2;
    vi S(n + 1), preJi(n + 1, 0), preOu(n + 1, 0);
    rep(i, 1, n) {
        cin >> S[i];
        if (S[i] & 1){
            preJi[i] = preJi[i - 1] + 1;
            preOu[i] = preOu[i - 1];
        }else{
            preOu[i] = preOu[i - 1] + 1;
            preJi[i] = preJi[i - 1];
        }
    }
    rep(i, 1, n){
        tot -= c - S[i] + 1;
        if (S[i] % 2 == 0){
            tot -= S[i] / 2 - preOu[i] + 1;
        }else{
            tot -= S[i] / 2 - preJi[i] + 1;
        }
    }
    cout << tot << endl;
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