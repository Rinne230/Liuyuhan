#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin() + 1, a.end()
//#define int ll
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 4e7 + 10;
const ll N = 3e7;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int sum[N], prime[N];
bool vis[maxn];
int ans[maxn];
int cnt = 0;

void getPrime(){
    for (int i = 2; i < maxn; ++i){
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; prime[j] < maxn / i; ++j){
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void init(){
    getPrime();
    for (int i = 0; i < cnt; ++i){
        int sum = 0;
        for (int j = i; j < cnt; ++j){
            sum += prime[j];
            if (sum > 4e7) break;
            ans[sum]++;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

signed main(){
    ios;
    init();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}