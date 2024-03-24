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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int q;
    cin >> q;
    while (q--){
        int ok1 = 1, ok2 = 0;
        for (int i = 1, x; i <= n; ++i){
            cin >> x;
            if (x){
                ok2 = 1;
                if (x != a[i]){
                   ok1 = 0;
                }
            }
        }
        if (ok1 && ok2){
            cout << "Da Jiang!!!" << endl;
        }else{
            cout << "Ai Ya" << endl;
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