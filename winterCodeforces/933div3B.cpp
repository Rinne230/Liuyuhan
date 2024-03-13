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
    vi a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 2; i < n; ++i){
        if (a[i] >= a[i - 1] * 2){
            int cnt = min(a[i - 1], a[i + 1]);
            if (a[i - 1] > a[i + 1]){
                cout << "NO" << endl;
                return;
            }
            a[i - 1] -= cnt;
            a[i + 1] -= cnt;
            a[i] -= cnt * 2;
        }
    }
    if (a[n] != a[n - 1] * 2){
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (a[i]) {
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
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