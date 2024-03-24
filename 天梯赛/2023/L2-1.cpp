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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int, vector<int>, less<int>> q2;
    int cnt = 0, mx = 0;
    for (int i = 1; i <= n; ++i){
        if (q1.empty() || a[i] < q1.top()){
            q1.push(a[i]);
        }else{
            if(q2.empty() || a[i] > q2.top()){
                q2.push(a[i]);
            }else{
                cnt++;
                int cur = 0;
                while (q1.size()){
                    q1.pop();
                    cur++;
                }
                mx = max(mx, cur);
                while (q2.size() && q2.top() > a[i]){
                    q1.push(q2.top());
                    q2.pop();
                }
                q1.push(a[i]);
            }
        }
    }
    if (q1.size()){
        cnt++;
        int cur = 0;
        while (q1.size()){
            q1.pop();
            cur++;
        }
        mx = max(mx, cur);
    }
    if (q2.size()){
        cnt++;
        int cur = 0;
        while (q2.size()){
            q2.pop();
            cur++;
        }
        mx = max(mx, cur);
    }
    cout << cnt << ' ' << mx << endl;
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