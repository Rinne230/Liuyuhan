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

void solve(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == t[i]) continue;
        if (s[i] == '1') cnt1++;
        if (t[i] == '1') cnt2++;
    }
    cout << max(cnt1, cnt2) << endl;
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