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
const ll maxn = 3e4 + 1;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vi f(maxn), d(maxn), cnt(maxn);
    for (int i = 1; i < maxn; ++i) f[i] = i, d[i] = 0, cnt[i] = 1;
    function<int(int)> find = [&](int x){
        if (x == f[x]) return x;
        int fa = find(f[x]);
        d[x] += d[f[x]];
        return f[x] = fa;
    };
    for (int i = 1; i <= n; ++i){
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'M'){
            int fx = find(x), fy = find(y);
            d[fx] += cnt[fy];
            f[fx] = fy;
            cnt[fy] += cnt[fx];
            cnt[fx] = 0;
        }else{
            if (find(x) != find(y)){
                cout << -1 << endl;
            }else{
                cout << abs(d[x] - d[y]) - 1 << endl;
            }
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