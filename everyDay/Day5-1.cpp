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
const ll mod = 99999997;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int tr[maxn];

int lowbit(int x) {return x & -x;}

void add(int x, int y){
    for(; x < maxn; x += lowbit(x)){
        tr[x] += y;
    }
}

int query(int x){
    int res = 0;
    for (; x; x -= lowbit(x)){
        res += tr[x];
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<pll> a(n + 1), b(n + 1);
    vi c(n + 1);
    rep(i, 1, n) cin >> a[i].first, a[i].second = i;
    rep(i, 1, n) cin >> b[i].first, b[i].second = i;
    sort(all(a));
    sort(all(b));
    for (int i = 1; i <= n; ++i) c[a[i].second] = b[i].second;
    int ans = 0;
    for (int i = n; i >= 1; --i){
        ans = (ans + query(c[i] - 1)) % mod;
        add(c[i], 1);
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