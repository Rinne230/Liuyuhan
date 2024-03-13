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
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    if (a % 2 == 0 || b % 2){
        cout << "No" << endl;
        return;
    }
    if (a - 1> 2 * b || b > 2 * a) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    vector<pll> son(sum + 5, pll(-1, -1));
    int st = 1, ed = 1;
    a--;
    int idx = 2;
    while (a || b){
        rep(j, st, ed){
            if(b == 0) break;
            son[j] = pll(idx, idx + 1);
            idx += 2;
            b -= 2;
        }
        st = ed + 1, ed = idx - 1;
        rep(j, st, ed){
            if (a == 0) break;
            son[j] = pll(idx, idx + 1);
            idx += 2;
            a -= 2;
        }
        st = ed + 1, ed = idx - 1;
    }
    rep(i, 1, sum){
        cout << son[i].x << " " << son[i].y << endl;
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