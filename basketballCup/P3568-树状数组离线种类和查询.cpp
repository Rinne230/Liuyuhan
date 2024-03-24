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
const ll N = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct BIT{
    int tr[N];
    int lowbit(int x){return x & -x;}
    void add(int x, int k){
        for (; x < N; x += lowbit(x)){
            tr[x] += k;
        }
    }
    int query(int x){
        int res = 0;
        for (; x; x -= lowbit(x)){
            res += tr[x];
        }
        return res;
    }
}tr1, tr2;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<char> op(m + 1);
    vi s(m + 1), b(m + 1), c(m + 1), p(n + 1, m + 1); //p是无用的位置
    for (int i = 1; i <= m; ++i){
        cin >> op[i];
        cin >> c[i] >> s[i];
        b[i] = s[i];
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for (int i = 1, idx, bidx; i <= m; ++i){
        if (op[i] == 'U'){
            idx = c[i]; //修改值的下标
            bidx = lower_bound(all(b), s[i]) - b.begin(); //修改值的离散值
            tr1.add(bidx, 1);
            tr1.add(p[idx], -1);
            tr2.add(bidx, b[bidx]);
            tr2.add(p[idx], -b[p[idx]]);
            p[idx] = bidx; //无用位置
        }else{
            bidx = lower_bound(all(b), s[i]) - b.begin();
            int cnt = tr1.query(m) - tr1.query(bidx - 1);
            int sum = tr2.query(bidx - 1);
            if (sum >= (c[i] - cnt) * s[i]){
                cout << "TAK" << endl;
            }else{
                cout << "NIE" << endl;
            }
        }
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