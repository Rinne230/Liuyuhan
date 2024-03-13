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
    string num;
    cin >> num;
    num = num.substr(2);
    int x = stoi(num);
    string s;
    cin >> s;
    int cntR = 0, cntP = 0, cnt = 0;
    for(auto i : s){
        cnt++;
        if(i == 'R') cntR++;
        else cntP++;
        if (cntR >= (x + 1) / 2){
            cout << "kou!" << endl;
            cout << cnt << endl;
            return;
        }
        if (cntP >= (x + 1) / 2){
            cout << "yukari!" << endl;
            cout << cnt << endl;
            return;
        }
    }
    cout << "to be continued." << endl;
    cout << cnt << endl;
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