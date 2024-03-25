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
    cin >> n;
    int ansl = 1, ansr = 1;
    vi P(n);
    for (int i = 0; i < n; ++i) {cin >> P[i];}
    for (int i = 0; i < n; ++i) P[i]--;
    string s;
    cin >> s;
    vi vis(n);
    for (auto i : P){
        if (vis[(i + 1) % n]){
            if (s[i] == '?') ansl = (ansl * 2) % mod;
        } else if (s[i] == 'R') ansl = 0;
        if (vis[(i - 1 + n) % n]){
            if (s[i] == '?') ansr = (ansr * 2) % mod;
        }else if (s[i] == 'L') ansr = 0;
        vis[i] = 1;
    }   
    cout << (ansl + ansr) % mod << endl;
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