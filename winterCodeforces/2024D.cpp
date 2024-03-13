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
    int n, cnt = 0;
    cin >> n;
    vi a(n + 1), st(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt += (a[i] == 0);
    }
    if (cnt != 1){
        cout << "No" << endl;
        return;
    }
    function<void()> check = [&](){
        stack<int> s;
        for (int i = 1; i <= n; ++i){
            while ((!s.empty()) && s.top() >= a[i]) s.pop();
            if ((!s.empty()) && s.top() == a[i] - 1) st[i] = 1;
            s.push(a[i]);
        }
    };
    check();
    reverse(all(a));
    reverse(st.begin() + 1, st.end());
    check();
    //for (int i = 1; i <= n; ++i) cout << st[i] << " \n"[i == n];
    cout << (accumulate(st.begin() + 1, st.end(), 0ll) == n - 1 ? "Yes" : "No") << endl;
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