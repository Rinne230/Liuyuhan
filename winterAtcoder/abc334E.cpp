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
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vi a(n + 1);
    map<int, int> nxt, pre;
    rep(i, 1, n){
        cin >> a[i];
        nxt[-1 * i] = a[i];
        pre[a[i]] = -i;
    }
    int q;
    cin >> q;
    while (q--){
        int op;
        cin >> op;
        if (op == 1){
            int x, y;
            cin >> x >> y;
            if (!nxt[x]){
                pre[y] = x;
                nxt[x] = y;
            }
            else{
                pre[nxt[x]] = y;
                nxt[y] = nxt[x];
                pre[y] = x;
                nxt[x] = y;
            }
        }else{
            int x;
            cin >> x;
            if (pre[x] && nxt[x]){
                nxt[pre[x]] = nxt[x];
                pre[nxt[x]] = pre[x];
                pre[x] = 0;
                nxt[x] = 0;
            }
            else if (pre[x]){
                nxt[pre[x]] = 0;
                pre[x] = 0;
                nxt[x] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        int tmp = -1 * i;
        while (nxt[tmp]){
            cout << nxt[tmp] << " ";
            tmp = nxt[tmp];
        }
    }
    
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