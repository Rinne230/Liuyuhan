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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int get_length(int x){
    int cnt = 0;
    while (x){
        x /= 10;
        cnt++;
    }
    return cnt;
}
void solve(){
    int ans = 0;
    for (int i = 1; i <= 100000000; ++i){
        int len = get_length(i);
        //if (i == 2314) cout << len << endl;
        if (len % 2 == 0){
            int cnt = len / 2;
            int x = i;
            int sum1 = 0, sum2 = 0;
            for (int j = 1; j <= cnt; ++j){
                sum1 += x % 10;
                x /= 10;
            }
            for (int j = 1; j <= cnt; ++j){
                sum2 += x % 10;
                x /= 10;
            }
            if (sum1 == sum2){
                ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios;
    int t = 1;
    //freopen("1.out", "w", stdout);
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}