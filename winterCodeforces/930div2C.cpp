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
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int query(int a, int b, int c, int d){
    cout << "? " << a << " " << b << " " << c << " " << d << '\n';
    cout.flush();
    char ch;
    cin >> ch;
    if (ch == '<')
        return 0;
    if (ch == '>')
        return 1;
    return 2;
}

void solve(){
    int n, mxid = 0, lstmax = 0, mnid = 0;
    cin >> n;
    for (int i = 1; i < n; ++i){
        if (query(mxid, mxid, i, i) == 0){
            mxid = i;
        }
    }
    vector<int> pending;
    pending.push_back(0);
    for (int i = 1; i < n; ++i){
        int res = query(mxid, lstmax, mxid, i);
        if (res == 0){
            pending.clear();
            pending.push_back(i);
            lstmax = i;
        }else if (res == 2){
            pending.push_back(i);
        }
    }
    mnid = pending[0];
    for (int i = 1; i < pending.size(); ++i){
        if (query(mnid, mnid, pending[i], pending[i]) == 1){
            mnid = pending[i];
        }
    }
    cout << "! " << mnid << " " << mxid << "\n";
    //cout.flush();
}

signed main(){
    //ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}