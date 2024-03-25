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
const ll N = 35;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int a[N];
int ans = inf64, n, m;
unordered_map<int, int> mp;

void dfs1(int cnt, int sum, int num){
    if (sum > m || num > ans) return;
    if (sum == m){
        ans = min(ans, num);
        return;
    }
    if (cnt == n / 2 + 1){
        if (sum <= m){
            if (mp.count(sum)) mp[sum] = min(mp[sum], num);
            else mp[sum] = num;
        }
        return;
    }
    dfs1(cnt + 1, sum, num);
    dfs1(cnt + 1, sum + a[cnt], num + 1);
    dfs1(cnt + 1, sum + a[cnt] * 2, num);
}

void dfs2(int cnt, int sum, int num){
    if (sum > m || num > ans) return;
    if (sum == m){
        ans = min(ans, num);
        return;
    }
    if (cnt == n + 1){
        if (sum <= m && mp.count(m - sum)){
            ans = min(ans, num + mp[m - sum]);
        }
        return;
    }
    dfs2(cnt + 1, sum, num);
    dfs2(cnt + 1, sum + a[cnt], num + 1);
    dfs2(cnt + 1, sum + a[cnt] * 2, num);
}

void solve(){
  
    cin >> n >> m;
    m *= 2;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    dfs1(1, 0, 0);
    dfs2(n / 2 + 1, 0, 0);
    if (ans == inf64) cout << -1 << endl;
    else cout << ans << endl;
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