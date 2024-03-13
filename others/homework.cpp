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

void solve(){
    int n;
    cin >> n;
    vector<vector<double>> mtx(n + 1, vector<double>(n + 1));
    vector<double> b(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mtx[i][j];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= n - 1; ++i){
        int mx = i;
        for (int j = i + 1; j <= n; ++j){
            if (abs(mtx[j][i]) > abs(mtx[mx][i]))
                mx = j;
        }
        swap(mtx[i], mtx[mx]);
        swap(b[i], b[mx]);
        for (int j = i + 1; j <= n; ++j){
            double rate = mtx[j][i] / mtx[i][i];
            for (int k = 1; k <= n; ++k)
                mtx[j][k] -= rate * mtx[i][k];
            b[j] -= rate * b[i];
        }
        cout << "step " << i << endl;
        for (int j = 1; j <= n; ++j){
            for (int k = 1; k <= n; ++k){
                cout << mtx[j][k] << " ";
            }
            cout << b[j] << endl;
        }
    }
    vector<double> x(n + 1);
    for (int i = n; i >= 1; --i){
        x[i] = b[i];
        for (int j = i + 1; j <= n; ++j)
            x[i] -= mtx[i][j] * x[j];
        x[i] /= mtx[i][i];
    }
    cout << "result: ";
    for (int i = 1; i <= n; ++i)
        cout << x[i] << " ";
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