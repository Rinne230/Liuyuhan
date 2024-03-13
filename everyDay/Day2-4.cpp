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

int a[maxn], b[maxn], c[maxn];
struct BIT
{
    int tr[maxn];
    int lowbit(int x){return x & -x;}
    void add(int x, int y){
        for(; x < maxn; x += lowbit(x)) tr[x] += y;
    }
    int query(int x){
        int res = 0;
        for(; x; x -= lowbit(x)) res += tr[x];
        return res;
    }
}tr[2];

void solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i], ++a[i], tr[0].add(a[i], 1);
    rep(i, 1, n) cin >> b[i], ++b[i];
    rep(i, 1, n) cin >> c[i], ++c[i], tr[1].add(c[i], 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int cnt1 = tr[0].query(b[i] - 1);
        int cnt2 = n - tr[1].query(b[i]);
        ans += cnt1 * cnt2;
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