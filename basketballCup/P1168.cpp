//对顶堆
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

priority_queue<int, vector<int>, less<int>> q1;
priority_queue<int, vector<int>, greater<int>> q2;
void solve(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    q1.push(x);
    cout << q1.top() << endl;
    for (int i = 2; i <= n; ++i){
        cin >> x;
        if (x > q1.top()){
            q2.push(x);
        }else{
            q1.push(x);
        }
        while (abs((int)q1.size() - (int)q2.size()) > 1){
            if (q1.size() > q2.size()){
                q2.push(q1.top());
                q1.pop();
            }else{
                q1.push(q2.top());
                q2.pop();
            }
        }
        if (i & 1){
            cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << endl;
        }
    }
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