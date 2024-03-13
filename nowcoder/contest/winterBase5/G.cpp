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
const ll maxn = 1e4 + 10;
const ll N = 1e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int notPrime[maxn];
vi prime;
int islink[N][N];
int aim[N], vis[N];
int n, ans = 0;

void getPrime(int n)
{
    rep(i, 2, n)
    {
        if (!notPrime[i])
            prime.push_back(i);
        for (auto p : prime)
        {
            if (i * p >= n)
                break;
            notPrime[i * p] = 1;
            if (i % p == 0)
                break;
        }
    }
}

bool find(int x){
    for (int j = 1; j <= n; ++j){
        if (islink[x][j] && (!vis[j])){
            vis[j] = 1;
            if ((!aim[j]) || find(aim[j])){
                aim[j] = x;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    memset(islink, 0, sizeof(islink));
    memset(aim, 0, sizeof(aim));
    ans = 0;
    cin >> n;
    getPrime(2 * n + 1);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (!notPrime[i + j]){
                islink[i][j] = islink[j][i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        memset(vis, 0, sizeof(vis));   
        if (find(i)) ans++;
    }
    if (ans != n){
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        cout << aim[i] << " "; 
    }
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