#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_set>
#include <bitset>
#define int long long
#define jacktan()            \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl '\n'
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 8e5 + 10;
const int mod = 1e9 + 7;
const int M = 1e9 + 20;
int n, m, k, p;
bool check(int v)
{
    if (v < 0)
        return 1;
    int val = v * p + 1;
    if ((val ^ (p - 1)) <= m)
        return 1;
    else
        return 0;
}
void solve()
{
    cin >> p >> m;
    int res = max((m / p) - 2, 0LL);
    int l = res;
    if (check(l)) res++;
    if ((l + 1) >= 0 && check(l + 1))
        res++;
    if ((l + 2) >= 0 && check(l + 2))
        res++;
    if ((l + 3) >= 0 && check(l + 3))
        res++;
    if ((l + 4) >= 0 && check(l + 4))
        res++;
    if ((l + 5) >= 0 && check(l + 5))
        res++;
    cout << res << endl;
}
signed main()
{
    jacktan();
    LL t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}