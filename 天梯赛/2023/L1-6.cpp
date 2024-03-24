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

void solve(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int a, b;
        string s1, s2;
        cin >> a >> b >> s1 >> s2;
        a--, b--;
        int len = b - a + 1;
        string tmp = s.substr(a, len);
        s2 = s1 + s2;
        s = s.substr(0, a) + s.substr(b + 1);
        //cout << "tmp : " << tmp << endl;
        //cout << "s : " << s << endl;
        //cout << s << endl;
        bool ok = 0;
        for (int i = 0; i < s.size(); ++i){
            if (i + s2.size() - 1 <= s.size() && s.substr(i, s2.size()) == s2){
                ok = 1;
                s = s.substr(0, i + s1.size()) + tmp + s.substr(i + s1.size());
                break;
            }
        }
        if (!ok){
            s += tmp;
        }
    }
    cout << s << endl;
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