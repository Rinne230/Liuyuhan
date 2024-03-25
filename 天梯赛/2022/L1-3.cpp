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
    int L, R;
    cin >> L >> R;
    int x, y;
    cin >> x >> y;
    if (x < L){
        if (y < L){
            cout << x << "-N " << y << "-N" << endl;
            cout << "zhang da zai lai ba" << endl;
        }else if (y >= R) {
            cout << x << "-Y " << y << "-Y" << endl;
            cout << "qing 2 zhao gu hao 1" << endl;
        }else{
            cout << x << "-N " << y << "-Y" << endl;
            cout << "2: huan ying ru guan" << endl;
        }
    }else if (x < R){
        if (y < L){
            cout << x << "-Y " << y << "-N" << endl;
            cout << "1: huan ying ru guan" << endl;
        }else{
            cout << x << "-Y " << y << "-Y" << endl;
            cout << "huan ying ru guan" << endl;
        }
    }else{
        if (y < L) {
            cout << x << "-Y " << y << "-Y" << endl;
            cout << "qing 1 zhao gu hao 2" << endl;
        }else {
            cout << x << "-Y " << y << "-Y" << endl;
            cout << "huan ying ru guan" << endl;
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