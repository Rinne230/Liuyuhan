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
const ll maxn = 2e6 + 10;
const ll N = 1e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int notPrime[maxn];
vi prime;
int n;

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

void solve()
{
    cin >> n;
    getPrime(2 * n);
    vi aim(n + 1);
    int idx = n;
    int tot = prime.size();
    for (int i = tot - 1; i >= 0; --i){
        if (prime[i] <= idx){
            int j = prime[i + 1];
            int tmp = idx;
            while (idx >= j - tmp){
                aim[idx] = j - idx;
                idx--;
            }
        }
    }
    if (idx == 1) aim[1] = 1;
    rep(i, 1, n) cout << aim[i] << " \n"[i == n];
}

signed main()
{
    ios;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}