#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define int ll
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n, m, x;
    cin >> n >> m >> x;
    int cnt = 0;
    set<int> cur, aft;
    cur.insert(x % n);
    for (int i = 1; i <= m; ++i){
        int r;
        char c;
        cin >> r >> c;
        for (auto cr : cur){
            if (c == '0') aft.insert((cr + r) % n);
            else if (c == '1') aft.insert((cr - r + n) % n);
            else{
                aft.insert((cr + r) % n);
                aft.insert((cr - r + n) % n);
            }
        }
        cur = aft;
        aft.clear();
    }
    cout << cur.size() << endl;
    vector<int> ans;
    for (auto i : cur){
        ans.push_back(i ? i : n);
    }
    sort(all(ans));
    for (auto i : ans){
        cout << i << ' ';
    }
    cout << endl;
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