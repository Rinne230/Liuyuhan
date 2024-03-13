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
const ll mod = 1e9 + 9;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int qpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int inv(int a)
{
    return qpow(a, mod - 2);
} 

vi ch(maxn);

void solve()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; ++i)
    {
        if (s[i] == '+')
            ch[i] = 1;
        else 
            ch[i] = -1;
    }
    int u = 0, ans = 0;
    for (int i = 0; i < k; ++i){
        u = ((u + ch[i] * qpow(b, i) % mod * inv(qpow(a, i) % mod) % mod) % mod + mod) % mod;
    }
    int q = qpow(b, k) * inv(qpow(a, k)) % mod;
    int num = (n + 1) / k;
    if (q == 1){
        cout << qpow(a, n) * u % mod * num % mod<< endl;
        return;
    }
    ans = u * (qpow(q, num) - 1) % mod * inv(q - 1) % mod;
    ans = (ans % mod + mod) % mod;
    cout << qpow(a, n) * ans % mod << endl;
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