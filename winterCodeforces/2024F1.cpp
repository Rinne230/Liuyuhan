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
const ll maxn = 5e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

ll n, q, a[maxn], b[maxn];
ll sum, T[maxn << 2], lazy[maxn << 2], c[maxn], v[maxn], sv[maxn];

void pushup(int x) {
    T[x] = max(T[x << 1], T[x << 1 | 1]);
}

void build(int l, int r, int x) {
    if (l == r) {
        T[x] = sv[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, x << 1);
    build(mid + 1, r, x << 1 | 1);
    pushup(x);
}

void pushdown(int x) {
    if (lazy[x]) {
        lazy[x << 1] += lazy[x];
        lazy[x << 1 | 1] += lazy[x];
        T[x << 1] += lazy[x];
        T[x << 1 | 1] += lazy[x];
        lazy[x] = 0;
    }
}

void update(int l, int r, int x, int ul, int ur, ll val) {
    if (l >= ul && r <= ur) {
        T[x] += val;
        lazy[x] += val;
        return;
    }
    pushdown(x);
    int mid = l + r >> 1;
    if (ul <= mid) update(l, mid, x << 1, ul, ur, val);
    if (ur > mid) update(mid + 1, r, x << 1 | 1, ul, ur, val);
    pushup(x);
}

void solve(){
    cin >> n >> q;
    int sum = 0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n - 1) cin >> c[i];
    per(i, n, 1){
        v[i] = a[i] - b[i];
        sv[i] = sv[i + 1] + v[i];
        sum += a[i];
    }
    build(1, n, 1);
    while(q--){
        int p, x, y, z;
        cin >> p >> x >> y >> z;
        sum -= a[p];
        update(1, n, 1, 1, p, -v[p]);
        a[p] = x, b[p] = y, v[p] = x - y;
        sum += a[p];
        update(1, n, 1, 1, p, v[p]);
        cout << sum - max(0ll, T[1]) << endl;
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