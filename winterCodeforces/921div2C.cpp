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
    int n, k, m;
    string s;
    cin >> n >> k >> m;
    cin >> s;
    vector<int> last(k + 1);
    int cnt = 0;
    int cycle = 0;

    string ans;

    vector<bool> check(k, true);

    for (int i = 0; i < s.size(); ++i)
    {
        if (check[s[i] - 'a'])
        {
            cycle++;
            check[s[i] - 'a'] = false;
        }
        if (cycle == k)
        {
            cnt++;
            cycle = 0;
            ans.push_back(s[i]);
            fill(check.begin(), check.end(), true);
        }
    }

    if (cnt >= n)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";

    cout << ans;
    for (int p = 0; p < n - ans.size(); ++p)
    {
        for (int i = 0; i < k; ++i)
            if (check[i])
            {
                cout << (char)(i + 'a');
                break;
            }
    }

    cout << endl;
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