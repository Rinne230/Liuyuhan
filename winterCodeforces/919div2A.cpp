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
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    vi uequl;
    int n;
    cin >> n;
    int mn = 1;
    int mx = inf32;
    for (int i = 1; i <= n; ++i){
        int tp, num;
        cin >> tp >> num;
        if (tp == 1) mn = max(num, mn);
        if (tp == 2) mx = min(mx, num);
        if (tp == 3) uequl.push_back(num);
    }
    int num = 0;
    for (auto x : uequl){
        if (x >= mn && x <= mx){
            num++;
        }
    }
    if (mn > mx) {
        cout << 0 << endl;
        return;
    }
    cout << mx - mn + 1 - num << endl;
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