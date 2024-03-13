#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define int ll
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int qmi(int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vi cnt(4);
    for (auto c : s){
        if (c == 'A') cnt[0]++;
        if (c == 'T') cnt[1]++;
        if (c == 'C') cnt[2]++;
        if (c == 'G') cnt[3]++;
    }
    sort(all(cnt));
    if (cnt[3] > cnt[2]) cout << 1 << endl;
    else if (cnt[2] > cnt[1]) cout << qmi(2, n) << endl;
    else if (cnt[1] > cnt[0]) cout << qmi(3, n) << endl;
    else cout << qmi(4, n) << endl;
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