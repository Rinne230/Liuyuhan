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
vector<set<tll>> s(13);
void init(){
    int a[13][3] = {{1, 2, 3}, {1, 3, 2}, {1, 2, 2}, {3, 1, 2}, 
                    {2, 1, 1}, {3, 2, 1}, {1, 1, 2}, {2, 2, 1}, {1, 1, 1}, 
                    {2, 3, 1}, {2, 3, 2}, {2, 1, 3}, {2, 1, 2}};
    rep(i, 0, 12){
        rep(j, 0, 2){
            rep(k, 0, 2){
                if (a[i][j] > a[i][k]){
                    tll tmp = {j + 1, k + 1, 1};
                    s[i].insert(tmp);
                }else{
                    tll tmp = {j + 1, k + 1, 0};
                    s[i].insert(tmp);
                }
            }
        }
    }
    
}
void solve(){
    int q;
    cin >> q;
    bool ok[13];
    rep(i, 0, 12) ok[i] = 1;
    while (q--){
        int a, b, c;
        cin >> a >> b >> c;
        tll tmp = {a, b, c};
        for (int i = 0; i < 13; ++i){
            if (!s[i].count(tmp)){
                ok[i] = 0;
            }
        }
    }
    for (int i = 0; i < 13; ++i){
        if (ok[i]) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

signed main(){
    ios;
    init();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}