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
    int n, m, k;
    cin >> n >> m >> k;
    stack<int> box;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int idx = 1;
    while (1){
        if (idx == n + 1 && box.empty()) break;
        vector<int> tmp;
        if (!box.empty()){
            tmp.push_back(box.top());
            box.pop();
        }else{
            tmp.push_back(a[idx++]);
        }
        while (1){
            if (tmp.size() == k) break;
            if (!box.empty()){
                if (box.top() <= tmp[tmp.size() - 1]){
                    tmp.push_back(box.top());
                    box.pop();
                }
                else if (idx <= n){
                    if (a[idx] <= tmp[tmp.size() - 1]){
                        tmp.push_back(a[idx++]);
                    }else if (box.size() < m){
                        box.push(a[idx++]);
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }else{
                if (idx <= n){
                    if (a[idx] <= tmp[tmp.size() - 1]){
                        tmp.push_back(a[idx++]);
                    }else if (box.size() < m){
                        box.push(a[idx++]);
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }
        }
        cout << tmp[0];
        for (int i = 1; i < tmp.size(); ++i) cout << " " << tmp[i];
        cout << endl;
    }
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