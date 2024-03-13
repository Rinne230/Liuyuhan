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
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;


int tr[maxn];

int lowbit(int x){
    return x & (-x);
}

void add(int x, int v){
    for (int i = x; i < maxn; i += lowbit(i)) tr[i] += v;   
}

int query(int x){
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += tr[i];
    return ans;
}

void solve(){
    memset(tr, 0, sizeof(tr));
    int n;
    cin >> n;
    vector<pair<int, int>> p(n + 1);
    map<int, int> mp;
    vi c(n + 1);
    rep(i, 1, n) cin >> p[i].x >> p[i].y;
    for (int i = 1; i <= n; ++i) mp[p[i].y] = 0;
    int idx = 0;
    for (auto &item : mp) item.y = ++idx;
    for (int i = 1; i <= n; ++i) p[i].y = mp[p[i].y];
    sort(all(p), [&](pair<int, int> a, pair<int, int> b){
        return a.x > b.x;
    });
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        add(p[i].y, 1);
        ans += query(p[i].y - 1);
    }
    cout << ans << endl;
}

signed main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}