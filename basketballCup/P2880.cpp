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
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
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
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector st1(n + 1, vi(20)), st2(n + 1, vi(20));
    rep(i, 1, n) st1[i][0] = st2[i][0] = a[i];
    rep(j, 1, 19){
        rep(i, 1, n){
            if(i + (1 << j) - 1 <= n){
                st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
                st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    auto query = [&](int l, int r){
        int k = 31 - __builtin_clz(r - l + 1);
        return max(st1[l][k], st1[r - (1 << k) + 1][k]) - min(st2[l][k], st2[r - (1 << k) + 1][k]);
    };
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
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