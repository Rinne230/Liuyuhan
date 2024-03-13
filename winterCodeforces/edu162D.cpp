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

int lower(int l, int r, function<bool(int)> f){
    if (!f(r)) return r + 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if (f(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve(){
    int n;
    cin >> n;
    vi a(n + 1), ld(n + 1), rd(n + 1), ans(n + 1), sum(n + 1);
    rep(i, 1, n) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    ld[1] = 0;
    for (int i = 2; i <= n; ++i){
        if (a[i] != a[i - 1]) ld[i] = i - 1;
        else ld[i] = ld[i - 1];
    }
    rd[n] = n + 1;
    for (int i = n - 1; i >= 1; --i){
        if (a[i] != a[i + 1]) rd[i] = i + 1;
        else rd[i] = rd[i + 1];
    }
    for (int i = 1; i <= n; ++i){
        int mn = 1e9;
        if (i > 1 && a[i] < a[i - 1]){
            ans[i] = 1;
            continue;
        }
        if (i > 1 && ld[i - 1] != 0){
            if (sum[i - 1] > a[i]){
                int l = lower(1, i - 1, [&](int idx){
                    return sum[i - 1] - sum[idx] <= a[i];
                });
                mn = min(mn, i - min(l, ld[i - 1]));
            }
        }

        if (i < n && a[i] < a[i + 1]){
            ans[i] = 1;
            continue;
        }
        if (i < n && rd[i + 1] != n + 1){
            if (sum[n] - sum[i] > a[i]){
                int r = lower(i + 1, n, [&](int idx){
                    return sum[idx] - sum[i] > a[i];
                });
                mn = min(mn, max(r, rd[i + 1]) - i);
            }
        }
        if (mn == 1e9) ans[i] = -1;
        else ans[i] = mn;
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
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