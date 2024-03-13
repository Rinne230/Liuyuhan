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
const ll maxn = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct BIT{
    int tr[maxn];
    int lowbit(int x) {return x & -x;}
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
    vi h(n + 1);
    rep(i, 1, n) cin >> h[i], h[i]++;
    int ans = 0;
    vi cnt(n + 1);
    for (int i = n; i >= 1; --i){
        tr[0].add(h[i], 1);
        cnt[i] = tr[0].query(h[i] - 1);
    }
    for (int i = 1; i <= n; ++i){
        tr[1].add(h[i], 1);
        cnt[i] += (i - tr[1].query(h[i]));
    }
    for (int i = 1; i <= n; ++i){
        ans += cnt[i] * (cnt[i] + 1) / 2;
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