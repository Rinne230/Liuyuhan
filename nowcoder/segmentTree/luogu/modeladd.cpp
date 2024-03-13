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
const ll maxn = 4e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int a[maxn], sum[maxn << 2], tag[maxn << 2];

void push_up(int x) {sum[x] = sum[x << 1] + sum[x << 1 | 1];}

void build(int u, int l, int r){
    tag[u] = 0;
    if (l == r) {sum[u] = a[l]; return;}
    int mid = (l + r) >> 1; 
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

inline void f(int u, int l, int r, int k){
    tag[u] += k;
    sum[u] += k * (r - l + 1);
}

inline void push_down(int u, int l, int r){
    int mid = (l + r) >> 1;
    f(u << 1, l, mid, tag[u]);
    f(u << 1 | 1, mid + 1, r, tag[u]);
    tag[u] = 0;
}

inline void update(int u, int nl, int nr, int l, int r, int k){
    if (nl <= l && r <= nr) {f(u, l, r, k); return;}
    push_down(u, l, r);
    int mid = (l + r) >> 1;
    if (nl <= mid) update(u << 1, nl, nr, l, mid, k);
    if (nr > mid) update(u << 1 | 1, nl, nr, mid + 1, r, k);
    push_up(u);
}

inline int query(int u, int qx, int qy, int l, int r){
    int res = 0;
    if (qx <= l && r <= qy) return sum[u];
    int mid = l + r >> 1;
    push_down(u, l, r);
    if (qx <= mid) res += query(u << 1, qx, qy, l, mid);
    if (qy > mid) res += query(u << 1 | 1, qx, qy, mid + 1, r);
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    build(1, 1, n);
    while(m--){
        int op, x, y, k;
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            update(1, x, y, 1, n, k);
        } else {
            cout << query(1, x, y, 1, n) << endl;
        }
    }
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