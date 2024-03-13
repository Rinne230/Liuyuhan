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
const ll maxn = 4e3 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int notprime[maxn], prime[maxn], cnt;
map<int, int> ok;
void init(){
    for (int i = 2; i < maxn; ++i){
        if (!notprime[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] < maxn; ++j){
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= 1e6; ++i){
        ok[i * i * i] = 1;   
    }
}

void solve(){
    int n;
    cin >> n;
    auto check = [&](int x){
        for (int i = 1; i <= cnt && prime[i] * prime[i] <= x; ++i){
            int sum = 0;
            while (x % prime[i] == 0){
                x /= prime[i];
                sum++;
            }
            if (sum == 1) return 0;
        }
        int k = sqrt(x);
        if (k * k == x) return 1;
        if (ok.count(x)) return 1;
        return 0;
    };
    for (int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        cout << (check(a) ? "yes" : "no") << endl;
    }

}

signed main(){
    ios;
    init();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}