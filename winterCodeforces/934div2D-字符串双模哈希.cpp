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
const ll mod1 = 998244353;
const ll mod2 = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct Hasher
{
    int x, y;
    inline Hasher(const int &X = 0, const int &Y = 0)
    {
        x = X;
        y = Y;
    }
    inline int get_val(void)
    {
        return ((1LL * x) << 31LL) | (1LL * y);
    }
    friend inline bool operator==(const Hasher &A, const Hasher &B)
    {
        return A.x == B.x && A.y == B.y;
    }
    friend inline Hasher operator+(const Hasher &A, const Hasher &B)
    {
        return Hasher((A.x + B.x) % mod1, (A.y + B.y) % mod2);
    }
    friend inline Hasher operator-(const Hasher &A, const Hasher &B)
    {
        return Hasher((A.x - B.x + mod1) % mod1, (A.y - B.y + mod2) % mod2);
    }
    friend inline Hasher operator*(const Hasher &A, const Hasher &B)
    {
        return Hasher(1LL * A.x * B.x % mod1, 1LL * A.y * B.y % mod2);
    }
} pw[N], H[N], R[N];

inline Hasher geth(int l, int r)
{
    return H[r] - H[l - 1] * pw[r - l + 1];
}
inline Hasher getr(int l, int r)
{
    return R[l] - R[r + 1] * pw[r - l + 1];
}

const Hasher base = Hasher(31, 131);

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    vi e1(n + 1), e2(n + 1);
    e1[n] = n;
    e2[n] = n;
    for (int i = n - 1; i >= 1; --i){
        if (s[i] == s[i + 1])
            e1[i] = e1[i + 1];
        else e1[i] = i;
        if (i < n - 1 && s[i] == s[i + 2])
            e2[i] = e2[i + 2];
        else e2[i] = i;
    }

    int i;
    for (pw[0] = Hasher(1, 1), i = 1; i <= n; ++i)
        pw[i] = pw[i - 1] * base;
    for (H[0] = Hasher(0, 0), i = 1; i <= n; ++i)
        H[i] = H[i - 1] * base + Hasher(s[i], s[i]);
    for (R[n + 1] = Hasher(0, 0), i = n; i >= 1; --i)
        R[i] = R[i + 1] * base + Hasher(s[i], s[i]);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (e1[l] >= r)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = (len + 2) * (len - 1) / 2;
        //cout << ans << endl;
        if (len % 2)
        {
            if (e2[l] >= r && e2[l + 1] >= r - 1)
            {
                ans -= (len / 2) * (3 + len) / 2;
                cout << ans << endl;
                continue;
            }
        }
        else
        {
            if (e2[l] >= r - 1 && e2[l + 1] >= r)
            {
                ans -= (len / 2 - 1) * (3 + len - 1) / 2;
                cout << ans << endl;
                continue;
            }  
        }
        if (geth(l, r) == getr(l, r))
        {
            ans -= r - l + 1;
        }
        //ans -= r - l + 1;
        cout << ans << endl;
    }
}

signed main()
{
    lyh;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}