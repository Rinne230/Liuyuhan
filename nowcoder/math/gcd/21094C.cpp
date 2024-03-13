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
const ll maxn = 46340 + 10;
const ll N = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int prime[maxn], cnt;
bool vis[maxn];
int p[N];

void getPrime()
{
    for (int i = 2; i < maxn; ++i)
    {
        if (!vis[i])
            prime[++cnt] = i;
        for (int j = 1; prime[j] <= (maxn - 10) / i; ++j)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
    for (int i = 1; i <= cnt && prime[i] <= r; ++i)
    {
        int w = (l + prime[i] - 1) / prime[i];
        for (int j = max(2ll, w); prime[i] * j <= r; ++j)
        {
            p[prime[i] * j - l] = 1;
        }
    }
    vi vec;
    for (int i = max(2ll, l); i <= r; ++i)
    {
        if (!p[i - l])
            vec.push_back(i);
        p[i - l] = 0;
    }
    if (vec.size() <= 1)
    {
        printf("There are no adjacent primes.\n");
        return;
    }
    pair<int, int> minn = {inf32, -1};
    pair<int, int> maxn = {-inf32, -1};
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i + 1] - vec[i] > maxn.first)
        {
            maxn.first = vec[i + 1] - vec[i];
            maxn.second = i;
        }
        if (vec[i + 1] - vec[i] < minn.first)
        {
            minn.first = vec[i + 1] - vec[i];
            minn.second = i;
        }
    }
    printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
           vec[minn.second], vec[minn.second + 1], vec[maxn.second],
           vec[maxn.second + 1]);
}

signed main()
{
    ios;
    getPrime();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}