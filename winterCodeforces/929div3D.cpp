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

int gcd(int a, int b) {
    if (b) while ((a%=b) && (b%=a));
    return a + b;
}
 
void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    int now = -1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (now == -1) {
            now = a[i];
        } else {
            now = gcd(now, a[i]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == now) cnt ++;
    }
    if (cnt < 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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