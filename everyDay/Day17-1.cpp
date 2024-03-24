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
const ll N = 3e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int n, m, p;

int query(int len[]){
    stack<int> s;
    int res = 0;
    for (int i = 1; i <= m + 1; ++i){
        while (!s.empty() && len[s.top()] > len[i]){
            int l = s.top();
            s.pop();
            res = max(res, len[l] * (s.empty() ? i : i - s.top() - 1));
        }
        s.push(i);
    }
    return res;
}

int len[N][N];

void solve(){
    cin >> n >> m >> p;
    vector vis(n + 1, vector(n + 1, 0));   
    while (p--){
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (!vis[i][j]){
                len[i][j] = len[i - 1][j] + 1;
            }
        }
    }
   
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, query(len[i]));
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