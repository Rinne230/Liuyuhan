#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
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

void mul(vector<vector<double>> &a, vector<vector<double>> &b){
    vector<vector<double>> res(a.size(), vector<double>(b[0].size(), 0));
    for (int i = 1; i < a.size(); i++){
        for (int j = 1; j < b[0].size(); j++){
            for (int k = 1; k < a[0].size(); k++){
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    a = res;
}

vector<vector<double>> qmi(vector<vector<double>> &a, int b){
    vector<vector<double>> res(a.size(), vector<double>(a.size(), 0));
    for (int i = 1; i < a.size(); i++){
        res[i][i] = 1;
    }
    while(b){
        if (b & 1){
            mul(res, a);
        }
        mul(a, a);
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, cnt;
    cin >> n >> cnt;
    vector A(n + 1, vector<double>(n + 1, 0));
    vector<double> b(n + 1, 0);
    vector mtx(n + 2, vector<double>(n + 2, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for (int i = 2; i <= n + 1; ++i){
        for (int j = 2; j <= n + 1; ++j){
            mtx[i][j] = (i == j ? 0 : (-A[i - 1][j - 1] / (A[i - 1][i - 1])));
        }
    }
    for (int i = 2; i <= n + 1; ++i){
        mtx[i][1] = b[i - 1] / (A[i - 1][i - 1]);
    }
    mtx[1][1] = 1;
    vector<vector<double>> res = qmi(mtx, cnt);
    vector<vector<double>> x(n + 2, vector<double>(2, 0));
    for (int i = 1; i <= n + 1; ++i)
        x[i][1] = 1;
    mul(res, x);
    for (int i = 1; i <= n; i++){
        cout << fixed << setprecision(10) << res[i + 1][1] << " ";
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