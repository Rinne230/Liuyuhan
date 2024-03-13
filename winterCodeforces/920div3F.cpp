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
typedef long long ll;
const ll maxn = 1e5 + 10;
const ll sqrtmaxn = 320;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int n, q, sqrtn;
int sum[maxn + sqrtmaxn][sqrtmaxn], suf[maxn + sqrtmaxn][sqrtmaxn];
int a[maxn];
int s, d, k;
void init(){
    cin >> n >> q;
    sqrtn = sqrt(n) + 1;
    rep(i, 1, n) cin >> a[i];
    for (int i = 1; i <= sqrtn; ++i){
        for (int j = n + 1; j <= n + sqrtn + 1; ++j) sum[j][i] = suf[j][i] = 0;
        for (int j = n; j >= 1; --j){
            sum[j][i] = sum[j + i][i] + suf[j + i][i] + a[j];
            suf[j][i] = suf[j + i][i] + a[j];
        }
    }
}
int query(){
    int res = 0;
    if (k < sqrtn){
        for (int i = 1, j = s; i <= k; ++i, j += d){
            res += i * a[j];
        }
        return res;
    }
    int t = s + d * k;
    if (t > n) return sum[s][d];
    return sum[s][d] - sum[t][d] - k * suf[t][d];
}
void solve(){
    init();
    while(q--){
        cin >> s >> d >> k;
        cout << query() << " ";
    }
    cout << endl;
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