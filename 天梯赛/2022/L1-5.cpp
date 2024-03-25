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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int vis[7][7];
void solve(){
    for (int i = 1; i <= 6; ++i){
        int x;
        cin >> x;
        vis[i][x] = 1;
    }
    int n;
    cin >> n;
    vi ans;
    for (int i = 1; i <= 6; ++i){
        int tmp = 0;
        for (int j = 6; j >= 1; --j){
            if (!vis[i][j]){
                tmp++;
            }
            if (tmp == n){
                ans.push_back(j);
                //cout << j << endl;
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " \n"[i == ans.size() - 1];
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