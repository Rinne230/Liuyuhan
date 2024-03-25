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
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

string get_s(string a)
{
    string s = "";
    for (int i = 1; i < a.length(); i++)
    {
        if (a[i] % 2 == a[i - 1] % 2)
        {
            s += max(a[i], a[i - 1]);
        }
    }
    return s;
}
void solve()
{
    string a1, a2;
    string s1 = "", s2 = "";
    cin >> a1 >> a2;
    s1 = get_s(a1);
    s2 = get_s(a2);
    if (s1 == s2){
        cout << s1 << endl;
    }else{
        cout << s1 << endl << s2 << endl;
    }
}

signed main()
{
    ios;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}