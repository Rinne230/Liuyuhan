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
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day(int n)
{
    int y = n / 10000;       
    int m = n % 10000 / 100; 
    int d = n % 10000 % 100; 

    a[2] = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0 ? 29 : 28); 
    while (m--)
        d += a[m]; 
    
    while (y--)
        d += (y % 4 == 0 && y % 100 != 0 || y % 400 == 0 ? 366 : 365); 
    return d;                                                          
}

signed main()
{
    int a, b;
    while (cin >> a >> b)
        cout << abs(day(a) - day(b)) + 1 << endl; 
}
