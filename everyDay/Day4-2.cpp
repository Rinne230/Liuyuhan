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
const ll maxn = 1e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

vector<int> G[maxn];

void solve(){
    int n, d, k;
    cin >> n >> d >> k;
    vector<pll> tsid(n + 1);
    map<int, int> ids;
    for (int i = 1; i <= n; ++i) cin >> tsid[i].x >> tsid[i].y;
    sort(all(tsid));
    for (int i = 1; i <= n; ++i){
        auto [ts, id] = tsid[i];
        G[id].push_back(ts);
        ids[id] = 1;
    }
    vector<int> ans;
    for (auto [key, value] : ids){
        int ok = 0;
        for (int i = 0; i < G[key].size() && !ok; ++i){
            int l = 0, r = 0;
            while (l <= r && r < G[key].size()){
                r++;
                while (G[key][r - 1] - G[key][l] >= d) l++;
                if (r - l >= k) {
                    ok = 1;
                    ans.push_back(key);
                    break;
                }
            }
        }
    }
    for (auto x : ans) cout << x << endl;
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