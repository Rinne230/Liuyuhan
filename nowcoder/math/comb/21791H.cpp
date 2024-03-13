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
    string s;
    cin >> s;
    int len = s.length();
    vi cnt(10);
    vi vis(10);
    vi f(20);
    int ans = 0;
    f[0] = 1;
    for (int i = 0; i < len; ++i){
        cnt[s[i] - '0']++;
    }
    for (int i = 1; i <= 19; ++i){
        f[i] = f[i - 1] * i;
    }
    function<void(int)> dfs = [&](int x) -> void{
        if (x == 10){
            int sum = 0;
            for (int i = 0; i <= 9; ++i) sum += vis[i];
            int tmp = 1;
            for (int i = 0; i <= 9; ++i) tmp *= f[vis[i]];
            ans += f[sum] / tmp;
            if (vis[0]) ans -= f[sum - 1] / (tmp / f[vis[0]] * f[vis[0] - 1]);
            return;
        }
        for (int i = 1; i <= cnt[x]; ++i){
            vis[x] = i;
            dfs(x + 1);
        }
        if (cnt[x] == 0) {
            vis[x] = 0;
            dfs(x + 1);
        }

    };
    dfs(0);
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