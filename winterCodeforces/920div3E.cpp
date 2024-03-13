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
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa >= xb) {
        cout << "Draw" << endl;
        return;
    }
    if ((xb - xa) % 2 == 0){
        if (ya == yb) {
            cout << "Bob" << endl;
            return;
        }
        else if (ya < yb){
            if (xb - xa >= 2 * (yb - 1)){
                cout << "Bob" << endl;
                return;
            }
            else {
                cout << "Draw" << endl;
                return;
            }
        }else{
            if(xb - xa >= 2 * (w - yb)){
                cout << "Bob" << endl;
                return;
            }
            else {
                cout << "Draw" << endl;
                return;
            }
        }
    }else{
        xa += 1;
        if (ya < yb) ++ya;
        else if (ya > yb) --ya;

        if (ya == yb){
            cout << "Alice" << endl;
            return;
        }
        else if (ya < yb){
            if (xb - xa >= 2 * (w - ya)){
                cout << "Alice" << endl;
                return;
            } 
            else {
                cout << "Draw" << endl;
                return;
            }
        }else{
            if(xb - xa >= 2 * (ya - 1)){
                cout << "Alice" << endl;
                return;
            }
            else {
                cout << "Draw" << endl;
                return;
            }
        }
    }
    cout << "Draw" << endl;
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