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
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    string s;
    cin >> s;
    n = s.size();
    s = " " + s + " 1145141919810";
    vi f(n + 1, 1);
    f[1] = 2;
    for (int i = 2; i <= n; ++i) 
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    vector<string> t = {"mygo", "m ygo", "my go", "myg o", "m y go", "m yg o", "my g o", "m y g o"};
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (auto &j : t){
            auto x = s.substr(i, j.size());
            auto check = [&](auto s, auto t){
                for (int i = 0; i < s.size(); ++i){
                    if (t[i] == ' ') continue;
                    if (s[i] != t[i]) return false;
                }
                return true;
            };
            if (check(x, j)){
               ans = (ans + 1ll * f[i - 1] * f[n - (i + j.size() - 1)] % mod) % mod;
            }
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