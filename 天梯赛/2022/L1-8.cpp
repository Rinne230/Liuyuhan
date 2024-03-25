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


int cnt1[301], cnt2[301];

void solve(){
    int n, k, l;
    cin >> n >> k >> l;
    vi ok(n + 1);
    vi vis(n + 1);
    for (int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;
        if (y >= l){
            cnt1[x]++;
        }else{
            cnt2[x]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i){
        for (int j = 175; j <= 300; ++j){
            if (cnt2[j] >= i){
                ans++;
            }
            if (i == 1) ans += cnt1[j];
        }
    }
    cout << ans << endl;
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