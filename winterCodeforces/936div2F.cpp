#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define int ll
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct BIT{
    vector<int> tr;
    int n;
    BIT(int n = 0) : n(n){
        tr.resize(n);
    }
    int lowbit(int x) {return x & -x;}
    void add(int x, int v){
        x++;
        for(; x <= n; x += lowbit(x)) tr[x - 1] += v;
    }
    int query(int x){
        int res = 0;
        x++;
        for(; x; x -= lowbit(x)) res += tr[x - 1];
        return res;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vi a(n), idx(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(all(a));
    for (int i = 0; i < n; i++) idx[a[i]] = i;
    vi res(q);
    vector<vector<pll>> qry(n);
    for (int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        l--, r--;
        l = n - l - 1;
        r = n - r - 1;
        swap(l, r);
        qry[r].emplace_back(l, i);
    }
    vi dp(n + 1);
    BIT tr(n);
    for (int r = 0; r < n; ++r){
        int x = a[r];
        dp[x] = 1;
        for(int y = x; y <= n; y += x){
            if (idx[y] > idx[x]) continue;
            for (int z = 2 * y; z <= n; z += y){
                if (idx[z] > idx[y]) continue;
                dp[z] += dp[y];
            }
        }
        for (int y = x; y <= n; y += x){
            tr.add(idx[y], dp[y]);
            dp[y] = 0;
        }
        for (auto [l, i] : qry[r]){
            res[i] += tr.query(r) - tr.query(l - 1);
        }
    }
    for (int i = 0; i < q; ++i){
        cout << res[i] << " \n"[i == q - 1];
    }
}

signed main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}