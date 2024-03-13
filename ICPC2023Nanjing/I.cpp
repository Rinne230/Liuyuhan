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
    int n, m;
    cin >> n >> m;
    vector<pll> val(m + 1);
    for (int i = 1; i <= m; ++i){
        cin >> val[i].x >> val[i].y;
    }
    sort(val.begin() + 1, val.end());
    for (int i = 1; i <= m; ++i){
        int Countdel = val[i].x - val[i - 1].x;
        int Valdel = val[i].y - val[i - 1].y;
        if (val[i].y == 0) continue;
        if (Countdel == 0) {
            if (i > 1 && val[i].y != val[i - 1].y){
                cout << "No" << endl;
                return;
            }
            continue;
        }
        if (Valdel <= 0){
            if (Countdel < val[i].y + 1){
                cout << "No" << endl;
                return;
            }
        }else{
            if (Valdel > Countdel) {
                cout << "No" << endl;
                return;
            }else {
                if (Countdel == Valdel) continue;
                if (Countdel < val[i].y + 1){
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
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