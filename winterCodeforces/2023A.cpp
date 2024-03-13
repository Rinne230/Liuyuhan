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
    const ll maxn = 2e5 + 10;
    const ll mod = 998244353;
    const ll inf32 = 1e9;
    const ll inf64 = 1e18;

    void solve(){
        int n, k, ans = 1;
        cin >> n >> k;
        vi a(n + 1);
        rep(i, 1, n){
            cin >> a[i];
            ans *= a[i];
        }
        if (2023 % ans) {
            cout << "No" << endl;
            return;
        }
        cout << "Yes" << endl;
        cout << 2023 / ans << " ";
        for (int i = 2; i <= k; ++i)
            cout << 1 << " ";
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