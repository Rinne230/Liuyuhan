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

int dp[maxn];
int a[] = {1, 3, 6, 10, 15};

void init(){
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    rep(i, 1, maxn - 1){
        rep(j, 0, 4){
            if(i - a[j] >= 0){
                dp[i] = min(dp[i - a[j]] + 1, dp[i]);
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    if (n < maxn) {
        cout << dp[n] << endl;
        return;
    }
    cout << min(n / 15 + dp[n % 15], n / 15 - 1 + dp[n % 15 + 15]) << endl;
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