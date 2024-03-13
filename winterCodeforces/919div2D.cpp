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
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;
struct node{
    __int128 m;
    int lst;
    vi t;
}tr[maxn];
int n, k, q;
int a[maxn], b[maxn];

void clear(int x){
    tr[x].m = tr[x].lst = 0;
    tr[x].t.clear();
}

void solve(){
    int idx = 1;
    clear(1);
    __int128 m = 0;
    cin >> n >> q;
    for (int i = 1, x, y; i <= n; ++i){
        cin >> x >> y;
        if (m >= 1e18) continue;
        if (x == 1){
            tr[idx].t.push_back(y);
            ++m;
        }else{
            clear(++idx);
            tr[idx].lst = m;
            m *= y + 1;
            tr[idx].m = m;
        }
    }
    for (int i = 1; i <= q; ++i){
        int x;
        cin >> x;
        int pos = idx, ans = -1;
        while (pos){
            if (x > tr[pos].m){
                ans = tr[pos].t[x - tr[pos].m - 1];
                break;
            }else{
                x = (x - 1) % tr[pos].lst + 1;
                --pos;
            }
        }
        cout << ans << " ";
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