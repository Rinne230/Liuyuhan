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
    int n, k, m;
    cin >> n >> k >> m;
    vi p(n + 1), c(n + 1), vis(n + 1);
    priority_queue<pll, vector<pll>, greater<pll>> P, C;
    priority_queue<int, vector<int>, greater<int>> del;
    rep(i, 1, n) {
        cin >> p[i] >> c[i];
        P.push({p[i], i});
        C.push({c[i], i});
    }
    for (int i = 1; i <= k; ++i) del.push(0);
    int ans = 0;
    while (!P.empty()){
        auto [pi, pid] = P.top();
        auto [ci, cid] = C.top();
        if (vis[pid]){
            P.pop();
            continue;
        }
        if (vis[cid]){
            C.pop();
            continue;
        }
        if (del.top() > pi - ci){ // 原价买更好
            m -= pi;
            P.pop();
            vis[pid] = 1;
        }else{
            m -= ci + del.top();
            del.pop();
            C.pop();
            vis[cid] = 1;
            del.push(p[cid] - c[cid]);
        }
        if (m >= 0) ans++;
        else break; 
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