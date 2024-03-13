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
const ll maxn = 2e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int m, n;
int a[maxn], b[maxn], c[maxn];

void merge(){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    for (int i = 1; i <= n; ++i)
        q.push({a[1] + b[i], 1});
    int cnt = 1;
    while (cnt <= n){
        auto [val, idx] = q.top();
        q.pop();
        c[cnt++] = val;
        q.push({val - a[idx] + a[idx + 1], idx + 1});
    }
    for (int i = 1; i <= n; ++i)
        a[i] = c[i];
}

void solve(){
    cin >> m >> n;
    m--;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    while (m--){
        for (int i = 1; i <= n; ++i)
            cin >> b[i];
        merge();
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " \n"[i == n];
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