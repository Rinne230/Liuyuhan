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
const ll N = 5e2 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int G[N][N];
void solve(){
    int n;
    cin >> n;
    vi ans(n + 1, -1), sex(n + 1, -1);
    memset(G, 0x3f, sizeof G);
    vector<int> p[2];
    for (int i = 1; i <= n; ++i){
        char sx;
        cin >> sx;
        if (sx == 'F') p[0].push_back(i), sex[i] = 0;
        else p[1].push_back(i), sex[i] = 1;
        int k;
        cin >> k;
        while (k--){
            string s, s1, s2;
            cin >> s;
            int idx = 0;
            for (int i = 0; i < s.size(); ++i){
                if (s[i] == ':'){
                    idx = i;
                    break;
                }
            }
            s1 = s.substr(0, idx);
            s2 = s.substr(idx + 1);
            int v = stoi(s1);
            int w = stoi(s2);
            G[i][v] = w;
        }
    }
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    for (auto x : p[0]){
        for (auto y : p[1]){
            ans[y] = max(ans[y], G[x][y]);
            ans[x] = max(ans[x], G[y][x]);
        }
    }
    int mn1 = inf32, mn2 = inf32;
    vi ans1;
    vi ans2;
    for (auto x : p[0]){
        if (ans[x] != -1){
            mn1 = min(mn1, ans[x]);
        }
    } 
    for (auto x : p[1]){
        if (ans[x] != -1){
            mn2 = min(mn2, ans[x]);
        }
    }
    for (auto x : p[0]){
        if (ans[x] == mn1){
            ans1.push_back(x);
        }
    }
    for (auto x : p[1]){
        if (ans[x] == mn2){
            ans2.push_back(x);
        }
    }
    for (int i = 0; i < ans1.size(); ++i){
        cout << ans1[i] << " \n"[i == ans1.size() - 1];
    }
    for (int i = 0; i < ans2.size(); ++i){
        cout << ans2[i] << " \n"[i == ans2.size() - 1];
    }
}

signed main(){
    ios;
    int t = 1;
    // /cin >> t;
    while(t--){
        solve();
    }
    return 0;
}