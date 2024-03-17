#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
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

int d[6][2] = {{1, 2}, {1, 3}, {2, 1}, {2, 3}, {3, 1}, {3, 2}};
void solve(){
    vi a(3);
    cin >> a[0] >> a[1] >> a[2];
    auto get_hash = [&](int x, int y, int z){
        return x * 10000 + y * 100 + z;
    };
    map<int, int> st;
    queue<tll> q;
    map<int, int> ans;
    q.push({0, 0, a[2]});
    while (!q.empty()){
        auto [x, y, z] = q.front();
        q.pop();
        if (st.count(get_hash(x, y, z))) continue;
        if (x == 0)
            ans[z] = 1;
        st[get_hash(x, y, z)] = 1;
        array<int, 3> p = {x, y, z};
        for (int i = 0; i < 6; ++i){
            auto [u, v] = d[i];
            u--, v--;
            int chg = min(p[u], a[v] - p[v]);
            array<int, 3> tmp = {p[0], p[1], p[2]};
            tmp[u] -= chg;
            tmp[v] += chg;
            q.push({tmp[0], tmp[1], tmp[2]});
        }
    }
    for (auto [x, y] : ans){
        cout << x << ' ';
    }
    cout << endl;
}

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}