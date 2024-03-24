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
    int n, m;
    cin >> n >> m;
    vector<pll> p(n + 1);
    vector<int> suf(n + 1);
    vector<vector<int>> pos(m + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
        suf[i] = p[i].x;
    }
    for (int i = n - 1; i >= 1; --i) suf[i] = max(suf[i], suf[i + 1]);
    priority_queue<tll, vector<tll>, less<tll>> q;
    int tim = m + 1;
    int tot = 0, l = 1;
    for (int i = 1; i <= m; ++i){
        int stu = 0;
        if (l <= n) stu = l;
        if (!q.empty()){
            auto [curk, curt, curi] = q.top();
            if (curk > suf[l]){
                stu = curi;
                q.pop();
            }
        }
        if (stu == l) l++;
        if (i + p[stu].y <= m){pos[i + p[stu].y].push_back(stu);}
        if (l > n) {
            cout << i << endl;
            return;
        }
        if (pos[i].size()){
            sort(pos[i].begin(), pos[i].end(),[&](int a, int b){
                return p[a].y < p[b].y;
            });
        }
        for (auto a : pos[i]){
            tim--;
            q.push({p[a].x, tim, a});
        }
        tim--;
    }
    cout << -1 << endl;
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