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
    int x, y;
    cin >> x >> y;
    if ((x ^ y) < x){
        cout << 1 << endl << x << " " << y << endl;
        return;
    }
    bitset<64> a(x), b(y);
    int cnt = 0;
    for (int i = 63; i >= 0; i--){
       if (a[i] == 1 && b[i] == 0) cnt++;
       if (a[i] == 0 && b[i] == 1){
            if (cnt < 2){
                cout << -1 << endl;
                return;
            }
       }
    }
    int hi = 0;
    for (int i = 63; i >= 0; --i) if (a[i] != b[i]) {hi = i; break;}
    cout << 2 << endl;
    int tmp = (x ^ y) ^ (1ll << hi);
    cout << x << " " << (x ^ tmp) << " " << y << endl;
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