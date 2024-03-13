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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

vector<vi> G;
bitset<N> red;
vector<int> white(N), S(N), a(N);
vector<int> dfsorder;

void dfs1(int u)
{
    for (auto v : G[u])
        dfs1(v);
    dfsorder.push_back(u);
}

void solve()
{
    ll n, t;
    cin >> n;
    G.resize(n + 1);
    string s;
    cin >> s;
    bitset<N> red; 
    rep(i, 0, n - 1) red[i + 1] = (s[i] == 'R');
    vector<ll> white(n + 1, 0); 
    rep(i, 2, n)
    {
        cin >> t;
        G[t].push_back(i);
        if (white[t] == 0 && !red[i])
            white[t] = i;
    }
    rep(i, 1, n) if (white[i] == 0 && red[i])
    {
        cout << "-1\n";
        return;
    }       
    dfs1(1); 
    ll S[N] = {0}, ans[N] = {0};
    for (auto &x : dfsorder)
    {
        for (auto &y : G[x])
            S[x] += S[y];
        if (red[x])
        {
            if (S[x] % 3 == 0)
            {
                ans[x] = 2;
                S[x] += 3;
                ans[white[x]] = 2;
                S[white[x]] += 1;
            }
            else if (S[x] % 3 == 1)
            {
                ans[x] = 2;
                S[x] += 2;
            }
            else
            {
                ans[x] = 1;
                S[x] += 1;
            }
        }
        else
        {
            ans[x] = 1;
            S[x] += 1;
        }
    }
    rep(i, 1, n)
        cout << ans[i];
    cout << endl;
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