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

double E = double(1e5) * double(19881   ) / double(39601); 
void solve(){
    int n, x, y, r;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        cin >> x >> y >> r;
        if (x <= 70 && x >= -70 && y <= 70 && y >= -70){
            cnt++;
        }
    }
    if (abs(double(cnt) - E) > 2000){
        cout << "buaa-noob" << endl;
    }else {
        cout << "bit-noob" << endl;
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