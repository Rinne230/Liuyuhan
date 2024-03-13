#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 3010;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

string s[maxn];
short dpl[maxn][maxn], dpr[maxn][maxn], dp[maxn][maxn], f[maxn + maxn][maxn];
int n, m;
ll ans = 0;
vector<pll> op[maxn];

void add(short f[], int x, int v){
    for (; x < maxn; x += (x & -x)) f[x] = f[x] + v;
}

int query(short f[], int x){
    int res = 0;
    for (; x; x -= (x & -x)) res = res + f[x];
    return res;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> s[i];
        s[i] = '.' + s[i] + '.';
    }
    for (int i = n; i >= 1; --i){
        for (int j = 1; j <= m; ++j){
            if (s[i][j] == '.') dpl[i][j] = dpr[i][j] = dp[i][j] = 0;
            else{
                dpl[i][j] = dpl[i + 1][j - 1] + 1;
                dpr[i][j] = dpr[i + 1][j + 1] + 1;
                dp[i][j] = dp[i][j - 1] + 1;
            }
        }
    }
    for (int i = n; i >= 1; --i){
        for (auto [j, k] : op[i]){
            add(f[j], k, -1);
        }
        for (int j = 1; j <= m; ++j){
            int k = min(dpl[i][j], dpr[i][j]);
            if (k >= 2){
                int t = j - i + 3000;
                ans += query(f[t], i + k - 1);
            }
        }
        for (int j = 1; j <= m; ++j){
            if (dp[i][j] >= 3){
                int t = (dp[i][j] + 1) / 2;
                add(f[j - i + 3000], i, 1);
                if (i - t > 0) op[i - t].push_back({j - i + 3000, i});
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}