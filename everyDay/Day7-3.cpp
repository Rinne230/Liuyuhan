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
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vi pre(n + 1, 0);
    vi nxt(n + 1, 0);
    vi lst(26, 0);
    for (int i = 1; i <= n; ++i){
        pre[i] = lst[s[i] - 'a'];
        lst[s[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; ++i) lst[i] = n + 1;
    for (int i = n; i >= 1; --i){
        nxt[i] = lst[s[i] - 'a'];
        lst[s[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int l = i - 1 - pre[i];
        int r = nxt[i] - i - 1;
        ans += l * r;
        ans += l + r + 1;
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