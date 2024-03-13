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
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int f[maxn][21];
int n, a[maxn], t;

void change(int x){
    f[x][0] = a[x];
    for (int i = 1; x - (1 << i) >= 0; ++i){
        f[x][i] = max(f[x][i - 1], f[x - (1 << (i - 1))][i - 1]);
    }
}

int find(int x, int y){
    int l = log2(y - x + 1);
    return max(f[y][l], f[x + (1 << l) - 1][l]);
}

void solve(){
    int m, p;
    cin >> m >> p;
    for (int i = 1; i <= m; ++i){
        char c;
        cin >> c;
        int x;
        if (c == 'A'){
            cin >> x;
            a[++n] = (x + t) % p;
            change(n);
        }else{
            int L;
            cin >> L;
            int ans;
            if (L == 1) {
                cout << a[n] << endl;
                t = a[n];
                continue;
            }
            ans = find(n - L + 1, n);
            cout << ans << endl;
            t = ans;
        }
    }
}

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}