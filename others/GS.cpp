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
    vector<vector<double>> a(n + 1, vector<double>(n + 1, 0));
    vector<double> b(n + 1);
    vector<double> x(n + 1, 1);
    rep(i, 1, n){
        rep(j, 1, n){
            cin >> a[i][j];
        }
    }
    rep(i, 1, n){
        cin >> b[i];
    }
    int cnt = 0;
    cin >> cnt;
    for (int op = 1; op <= cnt; ++op){
        for (int i = 1; i <= n; ++i){
            x[i] = b[i] / a[i][i];
            for (int j = 1; j <= n; ++j){
                if (i != j){
                    x[i] = x[i] - a[i][j] / a[i][i] * x[j];
                }
            }
        }
        for (int i = 1; i <= n; ++i){
            cout << x[i] << " \n"[i == n];
        }
    }
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