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

void solve(){
    int n;
    cin >> n;
    vi a(n + 1);
    bool ok = false;
    int cnt = 0;
    rep(i, 1, n){
        cin >> a[i];
        if (a[i] < 0) cnt++;
        if (a[i] == 0) ok = 1;
    }
    if (ok){
        cout << 0 << endl;
        return;
    }
    if (cnt & 1) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl << 1 << " " << 0 << endl;
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