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
    int n, Q, tc;
    cin >> n >> Q >> tc;
    vi t(n + 1), s(n + 1);
    rep(i, 1, n) cin >> t[i];
    sort(all(t));
    rep(i, 1, n) s[i] = s[i - 1] + t[i];
    while (Q--){
        int M;
        cin >> M;
        int l = 0, r = n;
        while (l < r){
            int mid = (l + r) >> 1;
            if ((n - mid) * tc <= M) r = mid;
            else l = mid + 1;
        }
        //cout << r << endl;
        cout << s[r] + tc << endl;
    }
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