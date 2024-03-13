#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 5e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int idx = 1;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n + 1), sum(n + 1);
    for (int i = 0; i < n; ++i){
        a[i + 1] = s[i] - '0';
    }
    for (int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = n / 2; i <= n; ++i){
        ans = max(ans, sum[i] - sum[i - (n + 1) / 2]);
    }
    cout << "Case #" << idx++ << ": " << ans << endl;
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