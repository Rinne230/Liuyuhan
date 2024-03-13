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
    int n;
    cin >> n;
    vi a(n + 1), f(n + 1);
    rep(i, 1, n) cin >> a[i];
    queue<int> que;
    for (int i = 1; i <= n; ++i){
        while (que.size() && a[i] != a[que.front()]){
            f[que.front()] = i;
            que.pop();
        }
        que.push(i);
    }
    while (que.size()){
        f[que.front()] = n + 1;
        que.pop();
    }
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        if (f[l] > r) {
            cout << "-1 -1" << endl;
        }else{
            cout << l << " " << f[l] << endl;
        }
    }
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