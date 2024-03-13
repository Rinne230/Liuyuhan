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
    int n, x;
    cin >> n >> x;
    vi a(n), sum(n);
    for (int i = 1; i <= n - 1; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    auto check = [&](int k){
        for (int i = 1; i < n - k + 1; ++i){
            if (sum[i + k - 1] - sum[i - 1] < 2 * x) return false;
        }
        return true;
    };
    int l = 1, r = n;
    while (l != r){
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
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