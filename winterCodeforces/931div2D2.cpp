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

void solve(){
    int n;
    cin >> n;
    if (bitset<64>(n).count() % 2){
        cout << "second" << endl;
        int p1, p2;
        cin >> p1 >> p2;
        if ((!p1) || (!p2)){
            return;
        }
        if (bitset<64>(p1).count() % 2 == 0){
            n = p1;
        }else{
            n = p2;
        }
    }else{
        cout << "first" << endl;
    }
    while (1){
        bitset<64> b(n);
        for (int i = 63; i >= 0; --i){
            if (b[i] == 0) continue;
            cout << (1ll << i) << " " << (n ^ (1ll << i)) << endl;
            cout.flush();
            break;
        }
        int p1, p2;
        cin >> p1 >> p2;
        if ((!p1) || (!p2)){
            return;
        }
        if (bitset<64>(p1).count() % 2 == 0){
            n = p1;
        }else{
            n = p2;
        }
    }
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