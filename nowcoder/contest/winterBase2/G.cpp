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
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;
struct STtree
{
#define type ll
#define ls (id << 1)
#define rs (id << 1 | 1)
    struct node
    {
        type mx, sum;
        void init()
        {
            mx = -inf64;
            sum = 0;
        }
    } t[maxn << 2];
    int n, ql, qr, qop;
    type a[maxn], bit[maxn], tag[maxn << 2], qv;
    node merge(node x, node y)
    {
        node res;
        res.sum = x.sum + y.sum;
        res.mx = max(x.mx, y.mx);
        return res;
    }
    void pushup(int id)
    {
        t[id] = merge(t[ls], t[rs]);
    }
    void pushdown(int l, int r, int id)
    {
        if (tag[id])
        {
            if (!tag[id])
                return;
            tag[ls] += tag[id];
            tag[rs] += tag[id];
            t[ls].mx += tag[id];
            t[rs].mx += tag[id];
            tag[id] = 0;
        }
    }
    void build(int l, int r, int id)
    {
        tag[id] = 0;
        t[id].init();
        if (l == r)
        {
            t[id].mx = bit[l] - 2 * a[l];
            t[id].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
        pushup(id);
    }
    void update(int l, int r, int id)
    {
        if (l >= ql && r <= qr)
        {
            if (qop == 1)
                t[id].sum = qv;
            else
            {
                t[id].mx += qv;
                tag[id] += qv;
            }
            return;
        }
        pushdown(l, r, id);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            update(l, mid, ls);
        if (qr > mid)
            update(mid + 1, r, rs);
        pushup(id);
    }
    node query(int l, int r, int id)
    {
        if (l >= ql && r <= qr)
            return t[id];
        pushdown(l, r, id);
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query(l, mid, ls);
        if (ql > mid)
            return query(mid + 1, r, rs);
        return merge(query(l, mid, ls), query(mid + 1, r, rs));
    }
    void upd(int l, int r, type v, int op)
    {
        ql = l;
        qr = r;
        qv = v;
        qop = op;
        update(1, n, 1);
    }
    void build(int _n)
    {
        n = _n;
        build(1, n, 1);
    }
    type ask_max(int l, int r)
    {
        ql = l;
        qr = r;
        return query(1, n, 1).mx;
    }
    type ask_sum(int l, int r)
    {
        if (l > r)
            return type(0);
        ql = l;
        qr = r;
        return query(1, n, 1).sum;
    }
#undef type
#undef ls
#undef rs
} tr;

void solve()
{
    int n, q, op, x, y;
    cin >> n >> q;
    tr.bit[0] = 0;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        tr.a[i] = a[i];
        tr.bit[i] = tr.bit[i - 1] + a[i];
    }
    tr.build(n);
    while (q--)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            tr.upd(x, x, 2 * a[x] - 2 * y, 2);
            tr.upd(x, n, y - a[x], 2);
            a[x] = y;
            tr.upd(x, x, a[x], 1);
        }
        else
        {
            cout << tr.ask_max(x + 1, y) - tr.ask_sum(1, x - 1) << endl;
        }
    }
}

signed main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}