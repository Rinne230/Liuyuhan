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
    string s;
    int n;
    cin >> n;
    cin >> s;
    s = " " + s;
    int cl = 0, cr = 0;
    vector S(2, vi(s.length() + 1, 0));
    vector tot(2, vi(s.length() + 1, 0));
    for (int i = 1; i <= n; ++i){
        if (s[i] == '>') {
            cl++;
            S[0][cl] = S[0][cl - 1] + i * 2;
        }else{
            cr++;
            S[1][cr] = S[1][cr - 1] + i * 2;
        }
        tot[0][i] = cl;
        tot[1][i] = cr;
    }
    for (int i = 1; i <= n; ++i){
        if (s[i] == '>'){
            if (tot[0][i] > cr - tot[1][i]){
                cout << S[1][cr] - S[1][tot[1][i]] - (S[0][tot[0][i]] - S[0][tot[0][i] - (cr - tot[1][i]) - 1]) + i + n + 1 << " ";
            }else{
                cout << S[1][tot[1][i] + tot[0][i]] - S[1][tot[1][i]] - S[0][tot[0][i]] + i << " ";
            }
        }else{
            if (cr - tot[1][i] + 1 > tot[0][i]){
                cout << S[1][tot[1][i] + tot[0][i]] - S[1][tot[1][i] - 1] - S[0][tot[0][i]] - i << " ";
            }else{
                cout << S[1][cr] - S[1][tot[1][i] - 1] - (S[0][tot[0][i]] - S[0][tot[0][i] - (cr - tot[1][i]) - 1]) - i + n + 1 << " ";
            }
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