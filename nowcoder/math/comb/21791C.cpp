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
    rep(i, 1, n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    if (a[2] < a[3]){
        for (int i = 3; i <= n; ++i) 
            if (a[i] == a[3]) ans++;
            else break;
    }
    else if (a[1] < a[2] && a[2] == a[3]){
        int tmp = 0;
        for (int i = 2; i <= n; ++i){
            if (a[i] == a[2]) tmp++;
            else break;
        }
        ans = tmp * (tmp - 1) / 2;
    }
    else if (a[1] == a[2] && a[2] == a[3]){
        int tmp = 0;
        for (int i = 1; i <= n; ++i){
            if (a[i] == a[1]) tmp++;
            else break;
        }
        ans = tmp * (tmp - 1) * (tmp - 2) / 6;
    }
    cout << ans << endl;
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