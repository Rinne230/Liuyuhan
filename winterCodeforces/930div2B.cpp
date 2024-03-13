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
    string s[2], fs = "";
    cin >> s[0] >> s[1];
    fs += s[0][0];
    int col = 0;
    int row = 0;
    int ans = 1;
    while (1){
        if (row == n - 1) break;
        if (s[col][row + 1] == '0' && s[col + 1][row] == '1'){
            fs += "0";
            ans = 1;
            row++;
        }else if (s[col][row + 1] == s[col + 1][row]){
            fs += s[col][row + 1];
            row++;
            ans++;
        }else{
            break;
        }
    }
    col = 1;
    for (int i = row; i < n; ++i){
        fs += s[col][i];
    }
    cout << fs << endl;
    cout << ans << endl;
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