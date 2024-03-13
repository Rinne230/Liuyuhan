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

vi dp(maxn, inf32);

void init(){
    dp[0] = 0;
    for (int i = 1; ; i++){
        int t = i * (i + 1) / 2;
        if (t > 2e5) break;
        for (int j = t; j <= 2e5; j++){
            dp[j] = min(dp[j], dp[j - t] + i + 1);
        }
    }
}

void solve(){
    int n, x, y, s;
    cin >> n >> x >> y >> s;
    int r = x % y;
    if (r * n > s){
        cout << "No" << endl;
        return;
    }
    s -= r * n;
    if (s % y){
        cout << "No" << endl;
        return;
    }
    s /= y;
    vi a(n + 1);
    a[1] = x / y;
    int pos = -1;
    int sum = a[1], k = a[1];
    for (int i = 1; i <= n && sum <= s; ++i){
        if (dp[s - sum] <= n - i){
            pos = i;
            break;
        }
        k++;
        sum += k;
    }
    if (pos == -1){
        cout << "No" << endl;
        return;
    }
    for (int i = 2; i <= pos; ++i){
        a[i] = a[i - 1] + 1;
    }
    s -= sum;
    int mn = dp[s];
    while (s > 0){
        for (int i = 1; ; ++i){
            int t = i * (i + 1) / 2;
            if (dp[s - t] + i + 1 == mn){
                s -= t;
                mn -= i + 1;
                for (int j = 0; j <= i; ++j) a[++pos] = j;
                break;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i){
        cout << a[i] * y + r << " \n"[i == n];
    }
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