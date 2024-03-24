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
    int n, m, q;
    cin >> n >> m >> q;
    while (q--){
        bool flag = 1;
        stack<int> s;
        int need = 1;
        vi a(n + 1);
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i){
            if (a[i] == need){
                need++;
                while (!s.empty() && s.top() == need){
                    s.pop();
                    need++;
                }
            }else{
                s.push(a[i]);
                if (s.size() > m){
                    flag = 0;
                }
            }
        }
        if (!flag || !s.empty()){
            cout << "NO" << endl;
            continue;
        }
        if (!flag){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
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