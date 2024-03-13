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
    vi vis1(3), vis2(3);
    int n;
    string s;
    cin >> n >> s;
    rep(i, 0, n - 1){
        if (s[i] == 'd') vis1[0] = 1;
        if (s[i] == 'f' && vis1[0]) vis1[1] = 1;
        if (s[i] == 's' && vis1[1]) vis1[2] = 1;
        if (s[i] == 'D') vis2[0] = 1;
        if (s[i] == 'F' && vis2[0]) vis2[1] = 1;
        if (s[i] == 'S' && vis2[1]) vis2[2] = 1;
    }
    cout << vis2[2] << " " << vis1[2] << endl;
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