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

int p;
int sum[N << 2];

void push_up(int rt){
    sum[rt] = (sum[rt << 1] * sum[rt << 1 | 1]) % p;
}

void build(int u, int l, int r){
    if (l == r){
        sum[u] = 1;
        return;
    }
    int mid = l + r >> 1;
    build (u << 1, l, mid);
    build (u << 1 | 1, mid + 1, r);
    push_up(u);
}

void update(int u, int nl, int nr, int l, int r, int x){
    if (l <= nl && nr <= r){
        sum[u] = x;
        return;
    }
    int mid = nl + nr >> 1;
    if (l <= mid) update(u << 1, nl, mid, l, r, x);
    if (r > mid) update(u << 1 | 1, mid + 1, nr, l, r, x);
    push_up(u);
}

void solve(){
    int n;
    cin >> n >> p;
    build(1, 1, n);
    rep(i, 1, n){
        int op, x;
        cin >> op >> x;
        if (op == 1){
            update(1, 1, n, i, i, x);
        }else{
            update(1, 1, n, x, x, 1);
        }
        cout << sum[1] % p << endl;
    }

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