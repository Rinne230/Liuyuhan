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

queue<int> q1, q2, q3;
int n, m, q, u, v, t;
void solve(){
    cin >> n >> m >> q >> u >> v >> t;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(all(a), [&](int x, int y){return x > y;});
    for (int i = 1; i <= n; ++i) q1.push(a[i]);
    for (int i = 1; i <= m; ++i){
        int mx = -inf64, opt = -1;
        if (!q1.empty()) if (q1.front() > mx) mx = q1.front(), opt = 1;
        if (!q2.empty()) if (q2.front() > mx) mx = q2.front(), opt = 2;
        if (!q3.empty()) if (q3.front() > mx) mx = q3.front(), opt = 3;
        if (opt == 1) q1.pop();
        else if (opt == 2) q2.pop();
        else if (opt == 3) q3.pop();
        mx += (i - 1) * q;
        int x = mx * u / v;
        int y = mx - x;
        if (!(i % t)) cout << mx << ' ';
        q2.push(x - i * q);
        q3.push(y - i * q);
    }
    cout << endl;
    int p = 1;
    while (p){
        int mx = -inf64, opt = -1;
        if (q1.empty() && q2.empty() && q3.empty()) break;
        if (!q1.empty()) if (q1.front() > mx) mx = q1.front(), opt = 1;
        if (!q2.empty()) if (q2.front() > mx) mx = q2.front(), opt = 2;
        if (!q3.empty()) if (q3.front() > mx) mx = q3.front(), opt = 3;
        if (opt == 1) q1.pop();
        else if (opt == 2) q2.pop();
        else if (opt == 3) q3.pop();
        if (p % t == 0){
            cout << mx + m * q << ' ';
        }
        p++;
    }
    cout << endl;
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