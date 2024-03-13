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
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int cnt1 = 0, cnt2 = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        if (a[i] & 1)
            cnt1++;
        else
            cnt2++;
        int ans = sum;
        int num1 = cnt1;
        ans -= num1 / 3;
        int num2 = cnt2;
        num2 += num1 / 3;
        num1 %= 3;
        if (num1 == 1 && num2) ans--;
        cout << ans << " \n"[i == n];
    }
}

signed main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}