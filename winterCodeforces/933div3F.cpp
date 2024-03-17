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
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), d(m + 1), f(k + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i];
    for (int i = 1; i <= k; i++)
        cin >> f[i];

    sort(d.begin(), d.end());
    sort(f.begin(), f.end());
    int mx1 = 0, p = 0, mx2;
    for (int i = 2; i <= n; i++){
        int t = (a[i] - a[i - 1]);
        if (t >= mx1){
            p = i;
            mx2 = mx1;
            mx1 = t;
        }else if (t > mx2){
            mx2 = t;
        }
    }
    if (mx1 == mx2){
        cout << mx1 << endl;
        return;
    }
    auto check = [&](int mid){
        for (int i = 1, j = k; i <= m && j >= 1; ++i){
            while (j >= 1 && d[i] + f[j] > a[p]) j--;
            while (j >= 1 && d[i] + f[j] > (a[p - 1] + a[p]) / 2){
                int res = d[i] + f[j];
                int mn = max(abs(res - a[p]), abs(res - a[p - 1]));
                if (mn <= mid) return true;
                j--;
            }
            if (j && d[i] + f[j] >= a[p - 1] && d[i] + f[j] <= a[p]){
                int res = d[i] + f[j];
                int mn = max(abs(res - a[p]), abs(res - a[p - 1]));
                if (mn <= mid) return true;
            }
        }
        return false;
    };

    int l = 0, r = mx1;
    while (l < r){
        int mid = (l + r) / 2;
        if (check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << max(r, mx2) << endl;
}

signed main()
{
    lyh;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}