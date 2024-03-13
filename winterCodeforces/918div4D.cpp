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

int check(char ch){
    if (ch == 'b' || ch == 'c' || ch == 'd') return 0;
    return 1;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> ans;
    for (int i = s.length() - 1; i >= 0; --i){
        if (!check(s[i])){
            ans.push_back(s.substr(i - 2, 3));
            i -= 2;
        }else{
            ans.push_back(s.substr(i - 1, 2));
            i--;
        }
    }
    reverse(ans.begin(), ans.end());   
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << ".\n"[i == ans.size() - 1];
    }
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