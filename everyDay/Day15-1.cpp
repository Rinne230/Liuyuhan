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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int fa[N], ans[N], val[N], sz[N];

int find(int x){
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void solve(){
    int n;
    cin >> n;
    iota(fa + 1, fa + n + 1, 1);
    fill(sz + 1, sz + n + 1, 1);
    int q;
    cin >> q;
    while (q--){
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1){
            int fx = find(x), fy = find(y);
            if (fx == fy) continue;
            for (int i = 1; i <= n; ++i){
                ans[i] += val[find(i)];
            }
            for (int i = 1; i <= n; ++i){
                val[i] = 0;
            }
            if (sz[fx] < sz[fy]){
                swap(fx, fy);
            }
            fa[fx] = fy;
            sz[fy] += sz[fx];
        }else{
            int fx = find(x);
            val[fx] += y;
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << ans[i] + val[find(i)] << ' ';
    }
    cout << endl;
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