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
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vi a(n + 2), d(n + 2);
    vi l(n + 2), r(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 1; i <= n; ++i){
        l[i] = i - 1;
        r[i] = i + 1;
    }
    vi m3, st(n + 2);
    for (int i = 1; i <= n; ++i) m3.push_back(i);
    for (int i = 1; i <= n; ++i){
        set<int> die;
        for (auto it : m3){
            if (a[l[it]] + a[r[it]] > d[it]){
                die.insert(it);
                st[it] = 1;
            }
        }
        cout << die.size() << " ";
        m3.clear();
        for (auto it : die){
            r[l[it]] = r[it];
            l[r[it]] = l[it];
            if (l[it] != 0 && st[l[it]] == 0) m3.push_back(l[it]);
            if (r[it] != n + 1 && st[r[it]] == 0) m3.push_back(r[it]);
        }
    }
    cout << endl;
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