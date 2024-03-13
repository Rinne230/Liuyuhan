// 并查集
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define all(a) a.begin(), a.end()
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
    int n, m;
    cin >> n >> m;
    vi f(n + 1);
    for (int i = 1; i <= n; ++i) f[i] = i;
    function<int(int)> find = [&](int x){
        return f[x] == x ? x : f[x] = find(f[x]);
    };
    vector<tuple<int, int, int>> e;
    for (int i = 1; i <= m; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        e.emplace_back(z, x, y);
    }
    sort(all(e));
    int num = n;
    for (auto [z, x, y] : e){
        int fx = find(x), fy = find(y);
        if (fx != fy){
            f[fx] = fy;
            num--;
            if (num == 1){
                cout << z << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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