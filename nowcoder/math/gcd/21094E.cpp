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
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int p[maxn], a[maxn], cnt;

void div(int x)
{
    memset(a, 0, sizeof a);
    cnt = 0;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            p[++cnt] = i;
            while (x % i == 0)
            {
                x /= i;
                a[cnt]++;
            }
        }
    }
    if (x != 1)
    {
        p[++cnt] = x;
        a[cnt] = 1;
    }
}

void solve(){
    int x;
    cin >> x;
    div(x);
    auto f = [&](int x){
        int res = 1;
        for (int i = 2; i <= x; ++i){
            res *= i;
        }
        return res;
    };
    int m = 0;
    for (int i = 1; i <= cnt; ++i) m += a[i];
    int ans = f(m);
    for (int i = 1; i <= cnt; ++i) ans /= f(a[i]);
    cout << m << " " << ans << endl;
}

signed main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}