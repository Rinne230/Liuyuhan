// 分块 RMQ 在线
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 1e6 + 10;
const ll maxm = 1e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int a[maxn], c[maxn], pos[maxn], fa[maxn], sz[maxn]; 
int mx[maxn], mn[maxm], l[maxm], r[maxm];
ll now, ans[maxn], lstans;
int n, m, T, block, tot;

vi v[maxn];

int find(int x){
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y){
    x = find(x), y = find(y);
    if (x == y) return;
    now -= 1ll * sz[x] * sz[x] + sz[y] * sz[y];
    sz[x] += sz[y];
    tot--;
    fa[y] = x;
    now += 1ll * sz[x] * sz[x];
}

bool cmp(int x, int y){
    return 1ll * ans[x] * c[y] < 1ll * ans[y] * c[x];
}

void query_t(int &res, int x, int y, int g[]){
    for (int i = x; i <= y; ++i){
        if (cmp(res, g[i])) res = g[i];
    }
}

int query(int x, int y){ //分块
    int res = 0;
    if (pos[x] == pos[y]) {query_t(res, x, y, mx); return res;}
    query_t(res, x, r[pos[x]], mx);
    query_t(res, l[pos[y]], y, mx);
    query_t(res, pos[x] + 1, pos[y] - 1, mn);
    return res;  
}

void solve(){   
    memset(l, 0x3f, sizeof l);
    cin >> n >> T;
    block = sqrt(n);    
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        c[i] = a[i];
        pos[i] = (i + block - 1) / block;
    }
    for (int i = 1; i <= n; ++i){
        fa[i] = i, sz[i] = 1;
        l[pos[i]] = min(l[pos[i]], i);
        r[pos[i]] = max(r[pos[i]], i);
    }
    sort(c + 1, c + n + 1);
    m = unique(c + 1, c + n + 1) - c - 1;
    for (int i = 1; i <= n; ++i){
        a[i] = lower_bound(c + 1, c + m + 1, a[i]) - c;
        v[a[i]].push_back(i);
    }
    ans[0] = -1;
    c[0] = 1;
    for (int x = 1; x <= m; ++x){
        now += v[x].size(); // 等于x的数字共有v[x].size()个, 平方和
        tot += v[x].size(); // 小于x的数构成的连续区间的个数
        for (auto it : v[x]){
            if (it != 1 && a[it - 1] <= x)  merge(it, it - 1);
            if (it != n && a[it + 1] <= x)  merge(it, it + 1);
        }
        ans[x] = now;
        if (cmp(mx[tot], x)){
            mx[tot] = x;
            if (cmp(mn[pos[tot]], x)){
                mn[pos[tot]] = x;
            }
        }
    }
    while (T--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a %= n, b %= n, x %= n, y %= n;
        int l = (1ll * a * lstans % n + x - 1 + n) % n + 1;
        int r = (1ll * b * lstans % n + y - 1 + n) % n + 1;
        if (l > r) swap(l, r);
        int res = query(l, r);
        if (!res) {
            cout << -1 << " " << -1 << endl << l << " " << r << " " << lstans << endl;
            lstans = 1;
        }else{
            cout << ans[res] << " " << c[res] << endl << l << " " << r << " " << lstans << endl;
            lstans = 1ll * (ans[res] % n) * (c[res] % n) % n;
        }
    }
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