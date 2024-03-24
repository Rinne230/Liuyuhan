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
const ll N = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct node{
    int win, lose;
}tr[N];

bool flag = true;

void check(int rt, int sz){
    if (rt * 2 > sz || !flag) return;
    int mx = tr[rt * 2].lose > tr[rt * 2 + 1].lose ? rt * 2 : rt * 2 + 1;
    int mn = tr[rt * 2].lose > tr[rt * 2 + 1].lose ? rt * 2 + 1 : rt * 2;
    if (tr[mx].lose > tr[rt].win || tr[mn].lose > tr[rt].lose){
        flag = false;
    }else if (tr[mx].lose > tr[rt].lose){
        tr[mx].win = tr[rt].win;
        tr[mn].win = tr[rt].lose;
        check(rt * 2, sz);
        check(rt * 2 + 1, sz);
    }else{
        tr[mx].win = tr[rt].lose;
        tr[mn].win = tr[rt].win;
        check(rt * 2, sz);
        check(rt * 2 + 1, sz);
        if (!flag) {
            flag = true;
            swap(tr[mx].win, tr[mn].win);
            check(rt * 2, sz);
            check(rt * 2 + 1, sz);
        }
    }

}

void solve(){
    int k;
    cin >> k;
    int sz = (1 << (k)) - 1;
    for (int i = k; i >= 1; --i){
        int n = (1 << (i - 1));
        int s = (2 << (i - 1)) - n;
        while (n--){
            cin >> tr[s].lose;
            s++;
        }
    }
    cin >> tr[1].win;
    if (tr[1].win < tr[1].lose){
        cout << "No Solution" << endl;
        return;
    }
    check(1, sz);
    if (!flag){
        cout << "No Solution" << endl;
        return;
    }
    int n = 1 << (k - 1);
    int s = (1 << k) - n;
    while (n--) {
        cout << tr[s].win << ' ' << tr[s++].lose;
        if (n) cout << ' ';
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