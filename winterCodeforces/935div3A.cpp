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
    int a, b, c;
    cin >> b >> a >> c; 
    int ans = 0;
    ans += b;
    if (a % 3 == 0){
        ans += (a + c + 2) / 3;
    }else if (a % 3 == 1){
        if (c <= 1){
            cout << -1 << endl;
            return;
        }
        ans += (a + c + 2) / 3;
    }else {
        if (c == 0){
            cout << -1 << endl;
            return;
        }
        ans += (a + c + 2) / 3;
    }
    cout << ans << endl;
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