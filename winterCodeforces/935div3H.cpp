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
    int n, X;
    cin >> n >> X;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    const int mx = *max_element(all(a));
    int t = __lg(mx);
    vi cnt(t + 1);
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= t; ++j){
            cnt[j] += (a[i] >> j & 1);
        }
    } 
    int state = 0;
    for (int i = 0; i <= t; ++i){
        if (cnt[i] == n - 1 || cnt[i] == n - 2){
            state |= 1 << i;
        }
    }
    vector<bool> mark(n + 1);
    vector<int> v;
    for (int i = 1; i <= n; ++i){
        bool ok = false;
        for (int j = 0; j <= t; ++j){
            if ((state >> j & 1) && !(a[i] >> j & 1)){
                ok = true;
                break;
            }
        }
        if (ok){
            mark[i] = true;
            v.push_back(i);
        }
    }
    int x1 = -1, x2 = -1;
    if (x1 == -1){
        for (auto x : v){
            for (int i = 1; i <= n; ++i){
                if (x == i) continue;
                int sum = 0;
                for (int k = 0; k <= t; ++k){
                    int add = (a[x] >> k & 1) + (a[i] >> k & 1);
                    if (cnt[k] - add == n - 2){
                        sum += (1 << k);
                    }
                }
                int val = __gcd(a[x], a[i]);
                if (val > sum + X){
                    x1 = i;
                    x2 = x;
                    break;
                }
            }
            if (x1 != -1) break;
        }
    }
    if (x1 == -1){
        vector<int> f(mx + 1);
        int sum = (1 << 30) - 1;
        for (int i = 1; i <= n; ++i){
            sum &= a[i];
            if (!mark[i]) f[a[i]]++;    
        }
        for (int i = 1; i <= mx; ++i){
            for (int j = 2 * i; j <= mx; j += i){
                f[i] += f[j];
            }
        }
        int g = 0;
        for (int i = mx; i >= 1; --i){
            if (f[i] >= 2){
                g = i;
                break;
            }
        }
        if (g > sum + X){
            for (int i = 1; i <= n; ++i){
                if (!mark[i] && a[i] % g == 0){
                    if (x1 == -1) x1 = i;
                    else if (x2 == -1) x2 = i;
                }
            }
        }
    }
    if (x1 == -1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << 2 << " " << a[x1] << " " << a[x2] << endl;
    cout << n - 2 << " ";
    for (int i = 1; i <= n; ++i){
        if (i != x1 && i != x2){
            cout << a[i] << " ";
        }
    }
    cout << endl;
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