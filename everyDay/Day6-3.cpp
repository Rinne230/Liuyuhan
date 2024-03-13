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
    int K, N;
    cin >> K >> N;
    vector<int> p(K);
    for (int i = 0; i < K; ++i) cin >> p[i];
    priority_queue<pll, vector<pll>, greater<pll>> q;
    for (int i = 0; i < K; ++i) q.push({p[i], i});
    queue<int> num[100];
    int res = 0;
    for (int i = 0; i < N; ++i){
        int x = q.top().x, y = q.top().y;
        q.pop();
        res = x;
        for (int j = y; j < K; ++j){
            num[j].push(x * p[j]);
            if (j == y){
                q.push({num[j].front(), j});
                num[j].pop();
            }
        }
    }
    cout << res << endl;
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