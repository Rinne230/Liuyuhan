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
    int t, a, k;
    cin >> t >> a >> k;
    if (t * a < 0){
        if (a >= -k && a <= k){
            cout << abs(a * 2) + abs(t) << endl;
        }else{
            cout << abs(a * 2) + abs(t * 3) << endl;
        }
    }else if (t * a == 0){
        if (t == 0){
            cout << abs(a * 2) << endl;
        }else{
            cout << abs(t) << endl;
        }
    }else{
        t = abs(t), a = abs(a);
        if (t < a){
            cout << a + (a - t) << endl;
        }else {
            cout << t << endl;
        }
    }
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