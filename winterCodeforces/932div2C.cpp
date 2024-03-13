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
        int n, L;
        cin >> n >> L;
        vector<pll> a(n + 1);
        rep(i, 1, n) cin >> a[i].x >> a[i].y;
        sort(all(a), [&](pll p1, pll p2){return p1.y < p2.y;});
        int ans = 0;
        for (int i = 1; i <= n; ++i){
            multiset<int> s;
            int cur = 0;
            for (int j = i; j <= n; ++j){
                s.insert(a[j].x);
                cur += a[j].x;
                while (!s.empty() && a[j].y - a[i].y + cur > L){
                    cur -= *s.rbegin();
                    s.extract(*s.rbegin());
                }
                ans = max(ans, (ll)s.size());
            }
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