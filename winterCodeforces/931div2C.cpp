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

int query(int x, int y){
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    int d1, d2, d3, d4;
    d1 = query(1, 1);
    if (d1 == 0){
        cout << "! " << 1 << " " << 1 << endl;
        return;
    }
    int lx = 1, ly = 1 + d1, rx = 1 + d1, ry = 1;
    if (ly > m){
        lx += ly - m;
        ly = m;
    }
    if (rx > n){
        ry += rx - n;
        rx = n;
    }
    d2 = query(lx, ly);
    if (d2 == 0){
        cout << "! " << lx << " " << ly << endl;
        return;
    }
    d3 = query(rx, ry);
    if (d3 == 0){
        cout << "! " << rx << " " << ry << endl;
        return;
    }
    int x1 = lx + d2 / 2, y1 = ly - d2 / 2, x2 = rx - d3 / 2, y2 = ry + d3 / 2;
    d4 = query(x1, y1);
    if (d4 == 0){
        cout << "! " << x1 << " " << y1 << endl;
    }else{
        cout << "! " << x2 << " " << y2 << endl;
    }
}

signed main(){
    //ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}