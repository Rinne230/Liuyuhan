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
map<string, string> mp;
map<string, int> flag;
bool word;
int a, b;
bool dfs(string x, string y)
{
    int num = 0;
    for (string i = x; !i.empty(); i = mp[i])
    {
        int sum = 0;
        for (string j = y; !j.empty(); j = mp[j])
        {
            if (i == j && (sum < 4 || num < 4))
                return false;
            if (num >= 4 && sum >= 4)
                return true;
            sum++;
        }
        num++;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2[s2.size() - 1] == 'm')
        {
            string s;
            for (int i = 0; i < s2.size() - 1; i++)
                s += s2[i];
            flag[s1] = 1;
        }
        if (s2[s2.size() - 1] == 'f')
        {
            string s;
            for (int i = 0; i < s2.size() - 1; i++)
                s += s2[i];
            flag[s1] = 2;
        }
        if (s2[s2.size() - 1] == 'n')
        {
            string s;
            for (int i = 0; i < s2.size() - 4; i++)
                s += s2[i];
            mp[s1] = s;
            flag[s1] = 1;
        }
        if (s2[s2.size() - 1] == 'r')
        {
            string s;
            for (int i = 0; i < s2.size() - 7; i++)
                s += s2[i];
            mp[s1] = s;
            flag[s1] = 2;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        word = false;
        if (flag[s1] == 0 || flag[s3] == 0)
            cout << "NA" << endl;
        else if (flag[s1] == flag[s3])
            cout << "Whatever" << endl;
        else
        {
            if (!dfs(s1, s3))
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
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