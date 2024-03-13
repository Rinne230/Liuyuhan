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

signed main(){
    ios;
    int n;
    while(cin >> n && n){
        vi a(n + 1), b(n + 1);
        rep(i, 1, n) cin >> a[i], b[i] = a[i];
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        rep(i, 1, n) a[i] = lower_bound(all(b), a[i]) - b.begin();
        vi tr(n + 2);
        auto lowbit = [&](int x){
            return x & -x;
        };
        auto add = [&](int x, int y){
            for(; x <= n; x += lowbit(x)) tr[x] += y;
        };
        auto query = [&](int x){
            int res = 0;
            for(; x; x -= lowbit(x)) res += tr[x];
            return res;
        };
        int ans = 0;
        for (int i = n; i >= 1; --i){
            ans += query(a[i] - 1);
            add(a[i], 1);
        }
        cout << ans << endl;
    }
    return 0;
}