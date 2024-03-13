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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int st = n, ed = -1;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'B') {
            st = i;
            break;
        }
    } 
    for (int i = n - 1; i >= 0; --i){
        if (s[i] == 'B'){
            ed = i;
            break;
        }
    }
    if (st > ed) {
        cout << 0 << endl;
    }else{
        cout << ed - st + 1 << endl;
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