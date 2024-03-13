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
const ll maxn = 1e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int n, m, ans;
int f[maxn * 3];

int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= 3 * n; ++i) f[i] = i;
    while (m--){
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n) {ans++; continue;}
        if (op == 1){
            if (find(x) == find(y + n) || find(y) == find(x + n)) {ans++;}
            else {
                f[find(x)] = find(y);
                f[find(x + n)] = find(y + n);
                f[find(x + 2 * n)] = find(y + 2 * n);
            }
        }else {
            if (find(x) == find(y) || find(x) == find(y + n)) {ans++;}
            else {
                f[find(x + n)] = find(y);
                f[find(x + 2 * n)] = find(y + n);
                f[find(x)] = find(y + 2 * n);
            }
        }
    }
    cout << ans << endl;
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