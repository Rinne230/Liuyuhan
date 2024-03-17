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
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vi st(n + 1);
    bool flag = false;
    vector p(n + 1, vi(3));
    for (int i = 1; i <= n; ++i){
        cin >> p[i][0] >> p[i][1] >> p[i][2];
        p[i][1] += p[i][0];
    }
    function<void(int, int)> dfs = [&](int cnt, int lst) {
        if (flag) return;
        if (cnt >= n){
            cout << "YES" << endl;
            flag = true;
        }
        for (int i = 1; i <= n; ++i){
            if (!st[i]){
                if (p[i][1] < lst) return;
                st[i] = true;
                if (lst < p[i][0]) dfs(cnt + 1, p[i][0] + p[i][2]);
                else dfs(cnt + 1, lst + p[i][2]);
                st[i] = false;
            }
        }
    };
    dfs(0, 0);
    if (!flag) cout << "NO" << endl; 
}

signed main(){
    lyh;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}