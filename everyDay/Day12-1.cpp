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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    int n;
    while (cin >> n && n)
    {
        int sum = 0;
        vi w(n + 1), st(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> w[i];
            sum += w[i];
        }
        sort(all(w), [&](int x, int y)
             { return x > y; });
        int len = 1;
        function<bool(int, int, int)> dfs = [&](int cur, int part, int pos){
            if (cur * len == sum)
                return true;
            if (part == len)
                return dfs(cur + 1, 0, 0);
            for (int i = pos; i <= n; ++i){
                if (st[i]) continue;
                if (w[i] + part > len) continue;
                st[i] = true;
                if (dfs(cur, part + w[i], i + 1))
                    return true;
                st[i] = false;
                if (!part || part + w[i] == len)
                    return false;
                int j = i;
                while (j <= n && w[j] == w[i]) j++;
                i = j - 1;
            }
            return false;
        };
        while (1){
            if (sum % len == 0 && dfs(0, 0, 0)){
                cout << len << endl;
                break;
            }
            len++;
        }
    }
}

signed main()
{
    lyh;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}