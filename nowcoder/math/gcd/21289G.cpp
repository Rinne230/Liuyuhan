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
const ll maxn = 1e5 + 10;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int n, m, q, w[maxn];
bool k;
int phi[maxn], tot = 0;
int qmi(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
            if (res >= mod) {
                k = true;
                res %= mod;
            }
        }
        a = a * a;
        if (a >= mod) {
            k = true;
            a %= mod;
        }
        b >>= 1;
    }
    return res;
}

int getPhi(int x)
{
    int res = 1;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            res = 1ll * res * (i - 1);
            x /= i;
            while (x % i == 0)
            {
                res = 1ll * res * i;
                x /= i;
            }
        }
    }
    if (x != 1)
        res = 1ll * res * (x - 1);
    return res;
}

void init(){
    int tmp = m;
    phi[++tot] = tmp;
    while (tmp != 1){
        tmp = getPhi(tmp);
        phi[++tot] = tmp;
    }
}

void solve(int l, int r){
    r = min(r, l + tot - 1);
    int res = 1;
    for (int i = r; i >= l; --i){
        k = false;
        res = qmi(w[i], res, phi[i - l + 1]);
        if (k) res += phi[i - l + 1];
    }
    cout << res % phi[1] << endl;
}

signed main(){
    ios;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    init();
    int t = 1, l, r;
    cin >> t;
    while(t--){
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}