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

int qmi(int a, int b){
    int res = 1;
    while(b){
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    vi a(9);
    iota(a.begin(), a.end(), 1);
    //for (int i = 0; i < 9; ++i) cout << a[i] << " \n"[i == 8];
    int ans = 0, n;
    cin >> n;
    do{
        vi sum(9);
        sum[0] = a[0];
        for (int i = 1; i < 9; ++i) sum[i] = sum[i - 1] * 10 + a[i];
        for (int i = 0; i < 7; ++i){
            if (sum[i] > n) break;
            for (int j = i + 1; j < 8; ++j){
                int x = sum[i], y = sum[j] - sum[i] * qmi(10, j - i), z = sum[8] - sum[j] * qmi(10, 8 - j);
                if (y % z == 0){
                    if (x + y / z == n) ans++;
                }
            }
        }
    }while(next_permutation(a.begin(), a.end()));
    cout << ans << endl;
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