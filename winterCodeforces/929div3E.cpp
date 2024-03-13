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
    vi a(n + 1), sum(n + 1);;
    rep(i, 1, n) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    int q;
    cin >> q;
    while (q--){
        int L, u;
        cin >> L >> u;
        int l = L, r = n;
        while (l < r){
            int mid = l + r >> 1;
            if (sum[mid] - sum[L - 1] <= u) l = mid + 1;
            else r = mid;
        }
        int ans = l - 1;
        int mx = -inf32, id = -1;
        for (int i = max(L, ans - 2); i <= min(n, ans + 2); ++i){
            int tmp = sum[i] - sum[L - 1];
            int tot  = (u + (u - tmp + 1)) * tmp / 2;
            if (tot > mx) {
                mx = tot;
                id = i;
            }
        }
        cout << id << " ";
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