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

void solve(){
    int n, len;
    cin >> n >> len;
    vi P(n + 1), S(n + 1);
    int l = 1, r = 2e9;
    rep(i, 1, n) cin >> P[i] >> S[i];
    auto check = [&](int x){
        vector<pll> segs;
        for(int i = 1; i <= n; i++)
        {
            int l = P[i], s = S[i];
            if(s > x) continue; 
            int left = max(1ll, l - x + s), right = min(len, l + x - s);
            segs.push_back({left, right});
        }
        int cnt = segs.size();
        sort(segs.begin(), segs.end()); 
        if(segs.empty()) return false;
        if(segs[0].first > 1) return false;

        int dr = segs[0].second;
        for(int i = 1; i < cnt; i++) 
        {
            if(segs[i].first > dr + 1) return false;
            dr = max(dr, segs[i].second);
        }
        return dr == len;

    };
    while (l < r){
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
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