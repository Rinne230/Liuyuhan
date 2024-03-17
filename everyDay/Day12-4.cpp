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
    int n, m, res = inf32;
    cin >> n >> m;
    vi mins(m + 1), minv(m + 1);
    vi R(m + 2), H(m + 2);
    for (int i = 1; i <= m; ++i){
        mins[i] = mins[i - 1] + 2 * i * i;
        minv[i] = minv[i - 1] + i * i * i;
    }
    R[m + 1] = inf32, H[m + 1] = inf32;
    function<void(int, int, int)> dfs = [&](int cur, int v, int s){
        if (v + minv[cur] > n) return;
        if (s + mins[cur] >= res) return;
        if (s + 2 * (n - v) / R[cur + 1] >= res) return;
        if (!cur){
            if (v == n) res = min(res, s);
            return;
        }
        for (int r = min(R[cur + 1] - 1, (int)sqrt((n - v - minv[cur - 1]) / (cur))); r >= cur; --r){
            for (int h = min(H[cur + 1] - 1, (n - v - minv[cur - 1]) / r / r); h >= cur; --h){
                H[cur] = h, R[cur] = r;
                int t = cur == m ? r * r : 0;
                dfs(cur - 1, v + r * r * h, s + 2 * r * h + t);
            }
        }
    };
    dfs(m, 0, 0);
    if (res == inf32) res = 0;
    cout << res << endl;
    
}   

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}