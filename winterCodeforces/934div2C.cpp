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
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vl a(n + 1), cnt(n + 1, 0);
    rep(i, 1, n) {
        cin >> a[i];
        if (a[i] <= n)
            cnt[a[i]]++;
    }
    bool ok = 1;
    rep(i, 0, n){
        if (cnt[i] == 0){
            cout << i << endl;
            return;
        }
        if (cnt[i] == 1 && ok){
            ok = 0;
        }else if (cnt[i] == 1){
            cout << i << endl;
            return; 
        }
    }
    cout << n << endl;
}

signed main(){
    lyh;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}