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
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (i + 4 <= n && s.substr(i, 5) == "mapie"){
            ans++;
            i += 4;
        }else if (i + 2 <= n && s.substr(i, 3) == "pie"){
            ans++;
            i += 2;
        }else if (i + 2 <= n && s.substr(i, 3) == "map"){
            ans++;
            i += 2;
        }
    }
    cout << ans << endl;
}

signed main(){
    lyh;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}