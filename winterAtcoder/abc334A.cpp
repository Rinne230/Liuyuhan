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
    cin >> s;
    int st = 0, ed = 0;
    for (int i = 0; i < s.length(); ++i){
        if (s[i] == '|'){
            st = i;
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; --i){
        if (s[i] == '|'){
            ed = i;
            break;
        }
    }
    for (int i = 0; i < s.length(); ++i){
        if (s[i] == '|'){
            continue;
        }
        if (i < st){
            cout << s[i];
        }
        else if (i > ed){
            cout << s[i];
        }
    }
    cout << endl;
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