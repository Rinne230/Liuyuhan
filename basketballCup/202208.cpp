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
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int fa[maxn];
int d[maxn];

int find(int x){
    if (fa[x] != x){
        int t = fa[x];
        fa[x] = find(t);
        d[x] += d[t];
    }
    return fa[x];
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    rep(i, 1, n) fa[i] = i;
    while (m--){
        int l, r, s;
        cin >> l >> r >> s;
        int pl = find(l - 1), pr = find(r);
        fa[pl] = pr;
        d[pl] = d[r] - d[l - 1] + s;
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        int pl = find(l - 1), pr = find(r);
        if (pl != pr) cout << "UNKNOWN" << endl;
        else cout << d[l - 1] - d[r] << endl;
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