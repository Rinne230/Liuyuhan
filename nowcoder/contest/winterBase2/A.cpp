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
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    if (a == 150) cnt++;
    if (a == 200) cnt += 2;
    if (b == 34 || b == 36 || b == 38 || b == 40) cnt++;
    else if (b == 45) cnt += 2;
    if (c == 34 || c == 36 || c == 38 || c == 40) cnt++;
    else if (c == 45) cnt += 2;
    cout << cnt << endl;
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