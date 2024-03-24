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
const ll N = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct BIT{
    int tr[N];
    int lowbit(int x){return x & -x;}
    void add(int x, int v){
        for (int i = x; i < N; i += lowbit(i)) tr[i] += v;
    }
    int query(int x){
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
}tr1, tr2;

void solve(){
    int n;
    cin >> n;
    vi a(n + 1);
    vi ans(n + 1, 0);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i]++;
        ans[i] += i - 1 - tr1.query(a[i]);
        tr1.add(a[i], 1);
    }
    reverse(all(a));
    for (int i = 1; i <= n; ++i){
        ans[n - i + 1] += tr2.query(a[i] - 1);
        tr2.add(a[i], 1);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i){
        res += (ans[i] * (ans[i] + 1)) / 2;
    }
    cout << res << endl;
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