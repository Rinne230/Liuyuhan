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
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct node{
    int val;
    int son[2];
}t[maxn * 32];
int cnt, n, k, a[maxn];

void init(){
    cnt = 1;
    for (int i = 0; i <= n * 32; ++i){
        t[i].son[0] = t[i].son[1] = 0;
        t[i].val = 0;
    }
}

void insert(int val, int x){
    int p = 1;
    for (int i = 30; i >= 0; --i){
        int c = (x >> i) & 1;
        if (t[p].son[c] == 0){
            t[p].son[c] = ++cnt;
        }
        p = t[p].son[c];
        t[p].val = (t[p].val + val) % mod;
    }   
}

int query(int x){
    int p = 1;
    int res = 0;
    for (int i = 30; i >= 0; --i){
        int c = (x >> i) & 1;
        int m = (k >> i) & 1;
        if (m){
            if (t[p].son[c]){
                res = (res + t[t[p].son[c]].val) % mod;
            }
            p = t[p].son[c ^ 1];
        }
        else p = t[p].son[c];
    }
    res = (res + t[p].val) % mod;
    return res;
}

int qmi(int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x){
    return qmi(x, mod - 2);
}

void solve(){
    cin >> n >> k;
    init();
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 1;
    for (int i = 2; i <= n; ++i){
        insert(inv(qmi(2, i - 1)), a[i - 1]);
        ans = (ans + 1 + query(a[i]) * qmi(2, i - 1)) % mod;
    }
    cout << ans << endl;
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