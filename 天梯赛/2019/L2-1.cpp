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

int vis[N], ok[N];

int nxt(int x){
    int sum = 0;
    while(x){
        sum += (x % 10) * (x % 10);
        x /= 10;
    }
    return sum;
}

int count(int x){
    int cnt = 0;
    while (1){
        if (x == 1){
            return cnt;
        }
        x = nxt(x);
        cnt++;
    }
}

int notprime[N], prime[N], cnt;

void init(){
    for (int i = 2; i < N; ++i){
        if (!notprime[i]){
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] < N; ++j){
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}

void solve(){
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i){
        vector<int> v(1001);
        int tmp = i;
        while (1){
            if (tmp == 1){
                ok[i] = 1;
                break;
            }    
            tmp = nxt(tmp);
            if (v[tmp]){
                break;
            }
            v[tmp] = 1;
            vis[tmp] = 1;
        }
    }
    bool flag = false;
    for (int i = a; i <= b; ++i){
        if (ok[i] && !vis[i]){
            flag = true;
            if (!notprime[i])
                cout << i << " " << 2 * count(i) << endl;
            else
                cout << i << " " << count(i) << endl;
        }
    }
    if (!flag){
        cout << "SAD" << endl;
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