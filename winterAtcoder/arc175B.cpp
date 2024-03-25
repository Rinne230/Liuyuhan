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
    int n, A, B;
    cin >> n >> A >> B;
    A = min(A, 2 * B);
    string s;
    cin >> s;
    int p = count(s.begin(), s.end(), '(');
    int q = 2 * n - p;
    int d = p - q;
    int res = 0;
    if (p > q){
        for (int i = 2 * n - 1; i >= 0; --i){
            if (s[i] == '(' && d){
                s[i] = ')';
                d -= 2;
                res += B;
            }
        }
    }else {
        for (int i = 0; i <= 2 * n - 1; ++i){
            if (s[i] == ')' && d){
                s[i] = '(';
                d += 2;
                res += B;
            }
        }
    }
    int sum = 0, mn = 0;
    for (int i = 0; i <= 2 * n - 1; ++i){
        sum += (s[i] == '(' ? 1 : -1);
        mn = min(mn, sum);
    }
    mn = -mn;
    res += (mn + 1) / 2 * A;
    cout << res << endl;
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