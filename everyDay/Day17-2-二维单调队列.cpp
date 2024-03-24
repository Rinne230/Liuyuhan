#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

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
using ll = long long;
using ull = unsigned long long;
const ll N = 1e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;
int s1[N][N], s2[N][N], s3[N][N], s[N][N];
void solve()
{
    int ans = 0;
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> s[i][j];
    for (int i = 1; i <= n; i++) // 求最小值
    {
        deque<int> q;
        for (int j = 1; j <= m; j++)
        {
            while (q.size() && q.back() <= j - b)
                q.pop_back();
            while (q.size() && s[i][q.front()] > s[i][j])
                q.pop_front();
            q.push_front(j);
            s1[i][j] = s[i][q.back()];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        deque<int> q;
        for (int i = 1; i <= n; i++)
        {
            while (q.size() && q.back() <= i - a)
                q.pop_back();
            while (q.size() && s1[q.front()][j] > s1[i][j])
                q.pop_front();
            q.push_front(i);
            s2[i][j] = s1[q.back()][j];
        }
    }

    for (int i = 1; i <= n; i++) // 求最大值
    {
        deque<int> q;
        for (int j = 1; j <= m; j++)
        {
            while (q.size() && q.back() <= j - b)
                q.pop_back();
            while (q.size() && s[i][q.front()] < s[i][j])
                q.pop_front();
            q.push_front(j);
            s1[i][j] = s[i][q.back()];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        deque<int> q;
        for (int i = 1; i <= n; i++)
        {
            while (q.size() && q.back() <= i - a)
                q.pop_back();
            while (q.size() && s1[q.front()][j] < s1[i][j])
                q.pop_front();
            q.push_front(i);
            s3[i][j] = s1[q.back()][j];
        }
    }
    for (int i = a; i <= n; i++)
    {
        for (int j = b; j <= m; j++)
        {
            ans = (ans + (s3[i][j] * s2[i][j]) % mod) % mod;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}