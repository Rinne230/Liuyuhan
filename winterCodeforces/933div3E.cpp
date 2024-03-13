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
const ll maxn = 3e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 5e18;

int mn[maxn << 2];
int a[maxn], dp[maxn];

void push_up(int x) {
    mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
}

void build(int u, int l, int r){
    if (l == r) {
        mn[u] = inf64; 
        return;
    }
    int mid = (l + r) >> 1; 
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void modify(int u, int x, int v, int l, int r){
    if (l == r) {
        mn[u] = v;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) modify(u << 1, x, v, l, mid);
    else modify(u << 1 | 1, x, v, mid + 1, r);
    push_up(u);
    return;
}

inline int query(int u, int qx, int qy, int l, int r){
    int res = inf64;
    if (qx <= l && r <= qy) return mn[u];
    int mid = l + r >> 1;
    if (qx <= mid) {
        res = query(u << 1, qx, qy, l, mid);
    }
    if (qy > mid){
        res = min(res, query(u << 1 | 1, qx, qy, mid + 1, r));
    }
    return res;
}

void solve(){
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vi ans(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[j];
            a[j]++;
            dp[j] = inf64;
        }
        build(1, 1, m);
        dp[1] = a[1];
        modify(1, 1, dp[1], 1, m);
        for (int j = 2; j <= m; ++j){
            int val = query(1, max(1ll, j - d - 1), j - 1, 1, m);
            dp[j] = min(dp[j], val + a[j]);
            modify(1, j, dp[j], 1, m);
        }
        ans[i] = dp[m];
    }
    for (int i = 1; i <= n; ++i){   
        ans[i] += ans[i - 1];
    }
    int res = inf64;
    for (int i = k; i <= n; ++i){
        res = min(res, ans[i] - ans[i - k]);
    }
    cout << res << endl;
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