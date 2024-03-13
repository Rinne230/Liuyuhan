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

int a[maxn], sum[maxn << 2], taga[maxn << 2], tagm[maxn << 2], p;

void push_up(int x) {sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % p;}

void build(int u, int l, int r){
    taga[u] = 0;
    tagm[u] = 1;
    if (l == r) {sum[u] = a[l]; return;}
    int mid = (l + r) >> 1; 
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

inline void push_down(int u, int l, int r){
    int m = l + r >> 1;
    int &tm = tagm[u], &ta = taga[u];
    if (tm != 1){
        taga[u << 1] = (taga[u << 1] * tm) % p;
        taga[u << 1 | 1] = (taga[u << 1 | 1] * tm) % p;
        tagm[u << 1] = (tagm[u << 1] * tm) % p;
        tagm[u << 1 | 1] = (tagm[u << 1 | 1] * tm) % p;
        sum[u << 1] = (sum[u << 1] * tm) % p;
        sum[u << 1 | 1] = (sum[u << 1 | 1] * tm) % p;
        tm = 1;
    }
    if (ta){
        taga[u << 1] = (taga[u << 1] + ta) % p;
        taga[u << 1 | 1] = (taga[u << 1 | 1] + ta) % p;
        sum[u << 1] = (sum[u << 1] + ta * (m - l + 1)) % p;
        sum[u << 1 | 1] = (sum[u << 1 | 1] + ta * (r - m)) % p;
        ta = 0;
    }
}

inline void update1(int u, int nl, int nr, int l, int r, int k){
    if (nl <= l && r <= nr) {
        tagm[u] = (tagm[u] * k) % p;
        taga[u] = (taga[u] * k) % p;
        sum[u] = (sum[u] * k) % p;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(u, l, r);
    if (nl <= mid) update1(u << 1, nl, nr, l, mid, k);
    if (nr > mid) update1(u << 1 | 1, nl, nr, mid + 1, r, k);
    push_up(u);
}

inline void update2(int u, int nl, int nr, int l, int r, int k){
    if (nl <= l && r <= nr) {
        taga[u] = (taga[u] + k) % p;
        sum[u] = (sum[u] + k * (r - l + 1)) % p;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(u, l, r);
    if (nl <= mid) update2(u << 1, nl, nr, l, mid, k);
    if (nr > mid) update2(u << 1 | 1, nl, nr, mid + 1, r, k);
    push_up(u);
}

inline int query(int u, int qx, int qy, int l, int r){
    int res = 0;
    if (qx <= l && r <= qy) return sum[u];
    int mid = l + r >> 1;
    push_down(u, l, r);
    if (qx <= mid) res = (res + query(u << 1, qx, qy, l, mid)) % p;
    if (qy > mid) res = (res + query(u << 1 | 1, qx, qy, mid + 1, r)) % p;
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m >> p;
    rep(i, 1, n) cin >> a[i];
    build(1, 1, n);
    while(m--){
        int op, x, y, k;
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            update1(1, x, y, 1, n, k);
        } else if (op == 2){
            cin >> k;
            update2(1, x, y, 1, n, k);
        } else{
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