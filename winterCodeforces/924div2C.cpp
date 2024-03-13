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

void solve() {
    int n, x;
    cin >> n >> x;
    set<int> ks;
    int fr = n - x;//上坡
    for (int i = 1; i <= fr / i; i ++) {
        if (fr % i == 0) {
            if (i % 2 == 0) {
                int k = (i + 2) / 2;
                if (k >= x) ks.insert(k);
            }
            int j = fr / i + 2;
            if (j % 2 == 0) {
                int k = j / 2;
                if (k >= x) ks.insert(k);
            }
        }
    }
    int ba = n + x - 2;//下坡
    for (int i = 1; i <= ba / i; i ++) {
        if (ba % i == 0) {
            if (i % 2 == 0) {
                int k = (i + 2) / 2;
                if (k >= x) ks.insert(k);
            }
            int j = ba / i + 2;
            if (j % 2 == 0) {
                int k = j / 2;
                if (k >= x) ks.insert(k);
            }
        }
    }
    cout << ks.size() << endl;
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