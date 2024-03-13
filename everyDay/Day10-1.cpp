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

struct node{
    int x, y;
    friend bool operator < (node a, node b){
        return a.x * b.y < b.x * a.y;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<node> a;
    map<pll, int> vis;
    for (int i = 1; i <= n; ++i)
        for (int j = i - 1; j; --j){
            int g = __gcd(i, j);
            if (vis[{i / g, j / g}]) continue;
            vis[{i / g, j / g}] = 1;
            a.push_back({j, i});
        }
           
    a.push_back({1, 1});
    a.push_back({0, 1});
    sort(all(a));
    for (auto i : a)
        cout << i.x << "/" << i.y << endl;
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