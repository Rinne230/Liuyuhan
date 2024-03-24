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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vi a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i){
        a[i] = s[i] - '0';
        sum += a[i];
        a[i] += a[i - 1];
    }
    int ans = -1;
    double d = double(inf32);
    for (int i = 1; i < n; ++i){
        int lfl = i - a[i];
        int rfr = sum - a[i];
        if (lfl >= (i + 1) / 2 && rfr >= (n - i + 1) / 2){
            if (abs((n) / 2.0 - double(i)) < d){
                ans = i;
                d = abs((n) / 2.0 - double(i));
            }
        }
    }
    //cout << d << endl;
    if (ans == -1){
        if (sum >= (n + 1) / 2){
            cout << 0 << endl;
        }else{
            cout << n << endl;
        }
        return;
    }
    cout << ans << endl;
}

signed main(){
    lyh;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}