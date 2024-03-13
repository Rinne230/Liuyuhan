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
    int L, M;
    cin >> L >> M;
    L++;
    vector<pll> a(M + 1);
    rep(i, 1, M){
        cin >> a[i].x >> a[i].y;
    }
    sort(all(a));
    int l = a[1].x, r = a[1].y;
    for (int i = 2; i <= M; i++){
        if (a[i].x <= r){
            r = max(r, a[i].y);
        }else{
            L -= r - l + 1;
            l = a[i].x;
            r = a[i].y;
        }
    }
    L -= r - l + 1;
    cout << L << endl;
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