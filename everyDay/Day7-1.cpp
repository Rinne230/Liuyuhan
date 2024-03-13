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
    string s;
    cin >> s;
    s = " " + s;
    vi nxt(n + 1), pre(n + 1);
    int lstG = 0, lstH = 0;
    for (int i = 1; i <= n; ++i){
        if (s[i] == 'G') {
            pre[i] = lstG;
            lstG = i;
        }
        else{
            pre[i] = lstH;
            lstH = i;
        }
    }
    lstG = n + 1, lstH = n + 1;
    for (int i = n; i >= 1; --i){
        if (s[i] == 'G') {
            nxt[i] = lstG;
            lstG = i;
        }
        else{
            nxt[i] = lstH;
            lstH = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int pl = pre[i], pr = nxt[i];
        if (pr - pl - 1 < 3) continue;
        int lc = i - pl - 1, rc = pr - i - 1;
        ans += lc * rc;
        ans += max(lc - 1, 0ll);
        ans += max(rc - 1, 0ll);
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