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
typedef long long ll;
const ll maxn = 3e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int C2(int x){
    return x * (x - 1) / 2ll;
}

int C3(int x){
    return x * (x - 1) / 2ll * (x - 2) / 3ll;
}

void solve(){
    int n;
    cin >> n;
    vi a(n + 1), cnt(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sum[0] = cnt[0];
    for (int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + cnt[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i){
        // cout << cnt[i] << " \n"[i == n];
        if (i >= 1)
            ans += C2(cnt[i]) * sum[i - 1] + C3(cnt[i]);
        else 
            ans += C3(cnt[i]);
    }
    cout << ans << endl;
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