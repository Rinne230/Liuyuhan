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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<vector<char>> ch(n, vector<char>(m));
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            cin >> ch[i][j];
        }
    }
    int p, q;
    cin >> p >> q;
    vector<pll> op;
    for (int i = 1; i <= q; ++i){
        int idx, pos;
        cin >> idx >> pos;
        pos--;
        op.push_back({idx, pos});
    }
    rep(i, 1, p){
        for (auto [idx, pos] : op){
            if (idx == 1){
                char tmp = ch[pos][m - 1];
                for (int j = m - 1; j >= 1; --j) ch[pos][j] = ch[pos][j - 1];
                ch[pos][0] = tmp;
            }else{
                char tmp = ch[n - 1][pos];
                for (int j = n - 1; j >= 1; --j) ch[j][pos] = ch[j - 1][pos];
                ch[0][pos] = tmp;
            }
        }
    } 
    // rep(i, 0, n - 1){
    //     rep(j, 0, m - 1){
    //         cout << ch[i][j];
    //     }
    //     cout << endl;
    // }
    cout << ch[x][y] << endl;
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