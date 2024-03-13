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

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int date){
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;
    if (!month || month > 12 || !day) return false;
    if (month != 2 && day > months[month]) return false;
    if (month == 2){
         bool leap = year % 4 == 0 && year % 100 || year % 400 == 0;
         if (day > 28 + leap) return false;
    }
    return true;
}

void solve(){
    int date1, date2;
    cin >> date1 >> date2;
    int res = 0;
    for (int i = 0; i < 10000; i ++ )
    {
        int x = i, r = i;
        for (int j = 0; j < 4; j ++ ) r = r * 10 + x % 10, x /= 10;

        if (r >= date1 && r <= date2 && check(r)) res ++ ;
    }
    cout << res << endl;
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