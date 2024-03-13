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
    vi a(n + 1);
    vector<string> s(n + 1);
    rep(i, 1, n){
        cin >> a[i] >> s[i];
    }
    vi vis(n + 1);
    int ans = 1;
    for (int i = 1; i <= n; ++i){
        if (vis[i]) continue;
        int j = i;
        while (vis[j] == 0){
            vis[j] = i;
            j = a[j];
        }
        if (vis[j] == i){
            int sum = 0;
            for (int k = 0; k < 5; ++k){
                int t = j;
                int c = s[j][k] - 'A';
                int chos = c;
                do {
                    t = a[t];
                    c = s[t][c] - 'A';
                }while(t != j);
                if (c == chos){
                    sum = (sum + 1) % mod;
                }
            }
            ans = ans * sum % mod;
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