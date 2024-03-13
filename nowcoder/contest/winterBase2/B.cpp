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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> vis(n + 2, vi(m + 2, 0));
    int ans = 0;
    while (k--){
        int x, y;
        cin >> x >> y;
        int del = 4;
        vis[x][y] = 1;
        if (vis[x - 1][y]) del--;
        if (vis[x + 1][y]) del--;
        if (vis[x][y - 1]) del--;
        if (vis[x][y + 1]) del--;
        ans += del;
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