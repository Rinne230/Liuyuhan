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
const ll N = 5e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    int n, C, cur = 0;
    cin >> n >> C;
    vector<string> s(n + 1);
    vi cnt(n + 1), ans(n + 1), room(N);
    priority_queue<pll> q;
    for (int i = 1; i <= n; ++i){
        cin >> s[i] >> cnt[i];
        q.push({cnt[i], i});
    }
    while (q.size()){
        auto [num, id] = q.top();
        q.pop();
        ans[id]++;
        if (num >= C){
            room[++cur] = 0;
            if (num > C){
                q.push({num - C, id});
            }
        }else{
            int ok = 0;
            for (int i = 1; i <= cur; ++i){
                if (room[i] >= num){
                    room[i] -= num;
                    ok = 1;
                    break;
                }
            }
            if (!ok){
                room[++cur] = C - num;
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << s[i] << " " << ans[i] << endl;
    }
    cout << cur << endl;
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