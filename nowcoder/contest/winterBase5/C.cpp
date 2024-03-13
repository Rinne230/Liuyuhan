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
    int n;
    cin >> n;
    vi a(n + 1), cntl(n + 1, inf32), cntr(n + 1, inf32);
    int sum = 0;
    rep(i, 1, n) {
        cin >> a[i];
        cntl[i - 1] = a[i] - 1;
        cntr[i] = a[i] - 1;
    }
    for (int i = 0; i <= n; ++i){
        //cout << i << " : " << cntl[i] << " " << cntr[i] << endl; 
        int tmp = min(cntl[i], cntr[i]);
        sum += tmp;
        cntr[i + 1] -= tmp;
    }
    cout << sum << endl;
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