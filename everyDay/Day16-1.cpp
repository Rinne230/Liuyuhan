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
const ll N = 1e2 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;
const double eps = 1e-6;

vector<pll> P;
double has[27];
int vis[N][N];
int id = 0;
vector<string> s(N);

double dis(pll a, pll b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get_hash(){
    double sum = 0;
    for (int i = 0; i < P.size(); ++i){
        for (int j = i + 1; j < P.size(); ++j){
            sum += dis(P[i], P[j]);
        }
    }
    return sum;
}

char get_id(double key){
    for (int i = 0; i < id; ++i){
        if (abs(has[i] - key) < eps){
            return i + 'a';
        }
    }
    has[id++] = key;
    return id - 1 + 'a';
}

void dfs(int x, int y){
    P.push_back({x, y});
    vis[x][y] = 1;
    for (int a = x - 1; a <= x + 1; ++a){
        for (int b = y - 1; b <= y + 1; ++b){
            if (a >= 0 && a < N && b >= 0 && b < N && !vis[a][b] && s[a][b] == '1'){
                dfs(a, b);
            }
        }
    }
}

void solve(){
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; ++i){
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            if (s[i][j] == '1'){
                if (!vis[i][j]){
                    P.clear();
                    dfs(i, j);
                    char c = get_id(get_hash());
                    for (auto p : P){
                        s[p.x][p.y] = c;
                    }
                }
            }
        }
    for (int i = 0; i < n; ++i)
        cout << s[i] << endl;
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