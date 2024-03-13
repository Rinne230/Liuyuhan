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

int qmi(int a, int b){
    int res = 1;
    while (b){
        if (b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int a, b, l;
    cin >> a >> b >> l;
    int cnta = 0;
    int cntb = 0;
    int tmp = l;
    while (tmp % a == 0){
        cnta++;
        tmp /= a;
    }
    tmp = l;
    while (tmp % b == 0){
        cntb++;
        tmp /= b;
    }
    int ans = 0;
    if (a == b){
        for (int i = 0; i <= cnta; ++i){
            if (l % qmi(a, i) == 0){
                ans++;
            }
        }
        cout << ans << endl;
        return;
    }
    map<int, int> cnt;
    for (int i = 0; i <= cnta; ++i){
        for (int j = 0; j <= cntb; ++j){
            int aa = qmi(a, i);
            int bb = qmi(b, j);
            if (aa * bb > l){
                continue;
            } 
            if (l % (aa * bb) == 0){
                cnt[l / (aa * bb)] = 1;
            }
        }
    }
    cout << cnt.size() << endl;
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