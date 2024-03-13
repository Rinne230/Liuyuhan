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

void solve(){
    string s;
    vi cnt(3);
    for (int i = 1; i <= 3; ++i){
        cin >> s;
        for (int j = 0; j < s.length(); ++j){
            if (s[j] == 'A') cnt[0]++;
            else if (s[j] == 'B') cnt[1]++;
            else cnt[2]++;
        }
    }
    
    if (cnt[0] == 2) cout << "A" << endl;
    else if (cnt[1] == 2) cout << "B" << endl;
    else cout << "C" << endl;
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