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
    int n;
    string s;
    getline(cin, s);
    n = s.size();
    vector<char> ans;
    for (int i = 0; i < n; ++i){
        if (s[i] != '6'){
            ans.push_back(s[i]);
        }else{
            int len = 0, ok = 0;
            string tmp = "";
            tmp.push_back(s[i]);
            for (int j = i + 1; j < n; ++j){
                if (s[j] != '6'){
                    ok = 1;
                    len = j - i;
                    i = j - 1;
                    break;
                }
                tmp.push_back(s[j]);
            }
            if (!ok){
                len = n - i;
                i = n;
            }
            if (len > 9){
                ans.push_back('2');
                ans.push_back('7');
            }else if (len > 3){
                ans.push_back('9');
            }else{
                for (auto c : tmp){
                    ans.push_back(c);
                }
            }
        }
    }
    for (auto c : ans){
        cout << c;
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