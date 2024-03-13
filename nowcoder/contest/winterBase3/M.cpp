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
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int getlen(int x){
    int len = 0;
    while(x){
        len++;
        x /= 10;
    }
    return len;
}

void solve(){
    int n;
    cin >> n;
    vi a(n + 1), fac10(20);
    fac10[0] = 1;
    for (int i = 1; i <= 18; ++i) fac10[i] = fac10[i - 1] * 10 % 36;
    vector<vi> amod(n + 1, vi(20, 0));
    vector<vi> lmod(20, vi(40));
    vi len(20);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        lmod[getlen(a[i])][a[i] % 36]++;
        for (int j = 1; j <= 18; ++j){
            amod[i][j] = ((a[i] % 36) * (fac10[j] % 36)) % 36;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= 18; ++j){
            int m = 36 - amod[i][j];
            if (m == 36) m = 0;
            ans += lmod[j][m];
            if (getlen(a[i]) == j && (a[i] % 36) == m) ans--;
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