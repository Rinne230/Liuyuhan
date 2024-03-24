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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

map<string, string> fp;
map<string, string> f;

void init(){
    fp["ChuiZi"] = "Bu";
    fp["JianDao"] = "ChuiZi";
    fp["Bu"] = "JianDao";
    f["ChuiZi"] = "JianDao";
    f["JianDao"] = "Bu";
    f["Bu"] = "ChuiZi";
}

void solve(){
    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int idx1 = 1, idx2 = 0;
    string s;
    cin >> s;
    while (s != "End"){
        if (idx1 > n){
            idx1 = 1;
        }
        if (idx2 == a[idx1]){
            cout << f[s] << endl;
        }else{
            cout << fp[s] << endl;
        }
        if (idx2 == a[idx1]){
            idx1++;
            idx2 = 0;
        }else{
            idx2++;
        }
        cin >> s;
    }
}

signed main(){
    lyh;
    int t = 1;
    init();
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}