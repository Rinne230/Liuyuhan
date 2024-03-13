#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin(), a.end()
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
vector<int> p2;
void init(){
    p2.push_back(1);
    rep(i, 1, 30){
        p2.push_back(p2.back() * 2);
    }
}

void solve(){
    int n;
    cin >> n;
    int k = upper_bound(all(p2), n) - p2.begin();
    cout << p2[k - 1] << endl;
}

signed main(){
    ios;
    init();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}