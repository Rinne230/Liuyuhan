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
    int n, S, k;
    cin >> n >> S >> k;
    if (n == 1){
        if (k == 0) cout << S << endl;
        else cout << -1 << endl;
        return;
    }
    if (n == 2){
        if (k == 0) cout << S / 2 << " " << S - S / 2 << endl;
        else cout << -1 << endl;
        return;
    }
    if (k == 0){
        for (int i = 1; i <= n - 1; ++i) cout << 1 << " ";
        cout << S - (n - 1) << endl;
        return;
    }
    if (n < 2 * k + 1) {
        cout << -1 << endl;
        return;
    }
    if (S < n + k + 1) {
        cout << -1 << endl;
        return;
    }
    vi ans;
    int t = (S - (n - k - 1)) / (k + 1);
    rep(i, 1, k){
        ans.push_back(t);
        ans.push_back(1);
        S -= t + 1;
    }
    ans.push_back(t);
    S -= t;
    if (ans.size() >= n){
        t = S / (n / 2);
        rep(i, 0, n / 2 - 1) {
            ans[i * 2 + 1] += t;
            S -= t;
        }
        t = 0;
        while (S){
            ans[2 * t + 1]++;
            t++;
            S--;
        }
        if (n > 1 && ans[1] >= ans[0]) {cout << -1 << endl; return;}
    }else{
        t = ans.size();
        while (ans.size() < n){
            ans.push_back(1);
            S--;
        }
        ans[t] += S;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
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