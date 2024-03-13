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
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    stack<int> st;
    st.push(a[1]);
    int ans = -1e18;
    for (int i = 2; i <= n; ++i)
    {
        if (st.empty()){
            st.push(a[i]);
        }else if ((abs(a[i]) % 2) != (abs(st.top()) % 2)){
            st.push(a[i]);
        }else{
            if (!st.empty())
            {
                int cur = st.top();
                st.pop();
                ans = max(cur, ans);
                while (!st.empty())
                {
                    int tmp = st.top();
                    st.pop();
                    cur = max({tmp, cur + tmp});
                    ans = max(cur, ans);
                    //cout << cur << endl;
                }
               
            }
            st.push(a[i]);
        }
    }
    if (!st.empty())
    {
        int cur = st.top();
        st.pop();
        ans = max(cur, ans);
        while (!st.empty())
        {
            int tmp = st.top();
            st.pop();
            cur = max({tmp, cur + tmp});
            ans = max(cur, ans);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}