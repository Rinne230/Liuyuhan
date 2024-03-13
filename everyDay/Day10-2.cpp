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
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

string s;
int k = 0;

int dfs(){
    int res = 0;
    while (k < s.size()){
        if (s[k] == '('){
            k++;
            res += dfs();
            k++;
        }else if (s[k] == ')'){
            return res;
        }else if (s[k] == '|'){
            k++;
            res = max(res, dfs());
        }else{
            k++;
            res++;
        }
    }
    return res;
}

void solve(){
   
    cin >> s;
    cout << dfs() << endl;
}

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}