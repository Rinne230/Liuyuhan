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
const ll maxn = 1e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;
const ull p = 13331;
ull P[maxn];
int pre[maxn], suf[maxn];

struct Hash
{
    int n;
    ull pre[maxn], suf[maxn];
    void init(const string &s){
        n = s.size() - 1;
        pre[0] = 0;
        for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] * p + s[i];
        suf[n + 1] = 0;
        for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] * p + s[i];
    }
    ull getpre(int l, int r){
        return pre[r] - pre[l - 1] * P[r - l + 1];
    }
    ull getsuf(int l, int r){
        return suf[l] - suf[r + 1] * P[r - l + 1];
    }
    bool pali(int l, int r){
        return getpre(l, r) == getsuf(l, r);
    }
}s, t;

void solve(){
    int n, m;
    cin >> n >> m;
    string ss, tt;
    cin >> ss >> tt;
    ss = " " + ss;
    tt = " " + tt;
    if (n > m) {
        swap(ss, tt);
        swap(n, m);
    }
    P[0] = 1;
    for (int i = 1; i < maxn; ++i) P[i] = P[i - 1] * p;
    s.init(ss);
    t.init(tt);
    for (int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1];
        if (s.pali(1, i) && s.getpre(1, i) == t.getpre(m - i + 1, m)) pre[i] = i;
    }
    for (int i = n; i >= 1; --i){
        suf[i] = suf[i + 1];
        if (s.pali(i, n) && s.getsuf(i, n) == t.getsuf(1, n - i + 1)) suf[i] = n - i + 1;   
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (pre[i] && suf[i + 1]) ans = max(ans, pre[i] + suf[i + 1]);
    }
    cout << (ans ? 2 * ans : - 1) << endl;
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