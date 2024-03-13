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

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
        return x = 1, y = 0, a;
    int r = exgcd(b, a % b, x, y);
    tie(x, y) = make_tuple(y, x - (a / b) * y);
    return r;
}

void solve(){
    int x, y, n, m, l, u, v, d, c;
    cin >> x >> y >> m >> n >> l;
    if (n > m){
        d = exgcd(n - m, l, u, v);
        c = x - y;
    }else{
        d = exgcd(m - n, l, u, v);
        c = y - x;
    }
    if (c % d){
        cout << "Impossible" << endl;
        return;
    }
    u = u * c / d;
    cout << (u % (l / d) + l / d) % (l / d) << endl;
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