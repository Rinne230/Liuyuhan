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
const ll N = 1e2 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int R, C;
int idx;
int op;
char g[N][N];
bool st[N][N];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y)
{
    st[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + d[i][0], ty = y + d[i][1];
        if (tx >= 0 && tx < R && ty >= 0 && ty < C && g[tx][ty] == '1' && !st[tx][ty])
        {
            dfs(tx, ty);
        }
    }
}

int query()
{
    memset(st, 0, sizeof st);
    int cnt = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (g[i][j] == '1' && !st[i][j])
            {
                cnt++;
                dfs(i, j);
            }
    return cnt;
}

void solve()
{
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
        cin >> g[i];
    }
    cin >> op;
    bool ok = false;
    for (int i = 1; i <= op; ++i)
    {
        char c;
        cin >> c;
        if (c == 'Q')
        {
            if (!ok)
            {
                cout << "Case #" << idx << ":" << endl;
                ok = 1;
            }
            cout << query() << endl;
        }
        else
        {
            int x, y, z;
            cin >> x >> y >> z;
            if (z == 1)
                g[x][y] = '1';
            else
                g[x][y] = '0';
        }
    }
}

signed main()
{
    lyh;
    int t = 1;
    cin >> t;
    while (t--)
    {
        idx++;
        solve();
    }
    return 0;
}