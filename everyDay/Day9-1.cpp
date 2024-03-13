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
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
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
    vector<pll> sec(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> sec[i].x >> sec[i].y;
    }
    sort(all(sec));
    int res1 = 0, res2 = 0;
    int l = sec[1].x, r = sec[1].y;
    for (int i = 2; i <= n; ++i){
        if (sec[i].x <= r){
            r = max(r, sec[i].y);
        }else{
            res1 = max(res1, r - l);
            res2 = max(res2, sec[i].x - r);
            l = sec[i].x;
            r = sec[i].y;        
        }
    }
    res1 = max(res1, r - l);
    cout << res1 << " " << res2 << endl;
}

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}