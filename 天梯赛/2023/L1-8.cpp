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

int get_sum(int x){
    int sum = 0;
    while (x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
void solve(){
    int a, b;
    cin >> a >> b;
    int sa = get_sum(a), sb = get_sum(b);
    int ok1 = 0, ok2 = 0;
    if (a % sb == 0){
        ok1 = 1;
    }
    if (b % sa == 0){
        ok2 = 1;
    }
    if (ok1 == ok2){
        if (a > b){
            cout << "A" << endl;
        }else{
            cout << "B" << endl;
        }
    }else if (ok1){
        cout << "A" << endl;
    }else if (ok2){
        cout << "B" << endl;
    }
}

signed main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}