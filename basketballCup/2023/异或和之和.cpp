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
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i <= 20; ++i){
        int od = 0;
        int len1 = 0, len2 = 0;
        for (int j = 0; j <= n; ++j){
            if (a[j] & (1 << i)){
                od = !od; 
            }
            if (!od){
                len2++;
                ans += len1 * (1 << i);
            }else{
                len1++;
                ans += len2 * (1 << i);
            }
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