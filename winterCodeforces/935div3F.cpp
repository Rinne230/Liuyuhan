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
    #define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
    using namespace std;
    using ll = long long;
    using ull = unsigned long long;
    const ll N = 2e5 + 10;
    const ll mod = 998244353;
    const ll inf32 = 1e9;
    const ll inf64 = 1e18;

    void solve(){
        int n;
        cin >> n;
        vector<pll> v(n + 1);
        vi val(n + 1);
        vi p(n + 1);
        map<int, int> cnt, vis;
        rep(i, 1, n) {
            cin >> v[i].x;
            v[i].y = i, val[i] = v[i].x;
        }
        rep(i, 1, n) cin >> p[i];
        sort(all(v));
        // for (int i = 1; i <= n; ++i){
        //     cout << v[i].x << " " << v[i].y << endl;
        // }
        int ans = v[n].x, mn = v[n].x, fp = 1;
        cnt[v[n].y] = 1;
        int cur = 1;
        for (int i = 2, j = n - 1; i <= n && j >= 1; ++i){
            vis[p[i - 1]] = 1;
            if (cnt[p[i - 1]]) {
                cnt[p[i - 1]] = 0;
                --cur;
            }
            while (cur < i){
                while (vis[v[j].y] && j) --j;
                if (j == 0) break;
                cnt[v[j].y] = 1;
                mn = min(mn, v[j].x);
                ++cur;
                j--;
            }
            if (cur == i){
                if (mn * i > ans){
                    ans = mn * i;
                    fp = i;
                }
            }
        }
        cout << ans << " " <<  fp << endl;
    }

    signed main(){
        lyh;
        int t = 1;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }