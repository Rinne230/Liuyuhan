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
    int n, m;
    cin >> m >> n;
    vector <int> a(n + 1);
    vector <int> deg(m + 1);
    vector <vector<int>> G(m + 1);
    vector <vector<int>> w(m + 1);
    for(int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        while(num--) {
            int x;
            cin >> x;
            w[i].push_back(x);
            a[x] = i;
        }
    }
    for(int i = 1; i <= m; i++) {
        for(auto j : w[i]) {
            if(a[j] == i) continue;
            deg[i]++, G[a[j]].push_back(i);
        }
    }
    // assert(0);
    vector <int> ord{0};
    priority_queue <int, vector<int>, greater<int>> q;
    for(int i = 1; i <= m; i++) {
        if(!deg[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        auto now = q.top();
        q.pop();
        ord.push_back(now);
        for(auto u : G[now]) {
            if(!--deg[u]) {
                q.push(u);
            }
        } 
    }
    reverse(ord.begin() + 1, ord.end());
    if(is_sorted(ord.begin(), ord.end())) {
        cout << "No\n";
        return ;
    }
    cout << "Yes\n";
    for(int i = 1; i <= m; i++) {
        cout << ord[i] << " \n"[i == m];
    }
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