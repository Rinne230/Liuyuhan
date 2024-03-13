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

void solve(){
    int n, m;
    cin >> n;
    vector<int> num(n + 1);
    vector<int> a(n + 2);
    rep(i, 1, n){
        cin >> num[i];
    }
    cin >> m;
    for (int i = 1, l, r; i <= m; ++i){
        cin >> l >> r;
        a[l] += 1;
        a[r + 1] -= 1;
    }
    int pre = 0, aft = 0; 
    for (int i = 1; i <= n; ++i){
        a[i] += a[i - 1];
        pre += a[i] * num[i];
    }
    sort(all(num), [&](int x, int y){
        return x > y;
    });
    sort(all(a), [&](int x, int y){
        return x > y;
    });
    for (int i = 1; i <= n; ++i){
        aft += a[i] * num[i];
    }
    cout << aft - pre << endl;
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