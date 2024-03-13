#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10, M = 1e6 + 10;
const int inf = 0x3f3f3f3f;

int n, a[N];
int path[M], pri[M], idx;
bool st[M];
int p[M];
int b[N], c[N], cnt1, cnt2;

void get_pri()
{
    int n = (int)1e6;
    for (int i = 2; i <= n; ++i)
    {
        if (!st[i])
        {
            pri[idx++] = i;
            path[i] = i;
        }
        for (int j = 0; i <= n / pri[j]; ++j)
        {
            st[i * pri[j]] = 1;
            path[i * pri[j]] = pri[j];
            if (i % pri[j] == 0)
                break;
        }
    }
}

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    get_pri();
    while (q--)
    {
        cin >> n;
        int ma = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            p[a[i]] = a[i];
            ma = max(ma, a[i]);
        }
        for (int i = 0; pri[i] <= ma; ++i)
            p[pri[i]] = pri[i];
        p[1] = 1;

        for (int i = 1; i <= n; ++i)
        {
            int t = a[i], pa = find(a[i]);
            while (t != 1)
            {
                int d = path[t];
                int pb = find(d);
                if (pa != pb)
                    p[pb] = pa;
                t /= d;
            }
        }
        cnt1 = cnt2 = 0;
        int pa = find(a[1]);
        b[cnt1++] = a[1];
        for (int i = 2; i <= n; ++i)
        {
            int pb = find(a[i]);
            if (pb == pa)
                b[cnt1++] = a[i];
            else
                c[cnt2++] = a[i];
        }

        if (cnt2 == 0)
            cout << -1 << " " << -1 << "\n";
        else
        {
            cout << cnt1 << " " << cnt2 << "\n";
            for (int i = 0; i < cnt1; ++i)
                cout << b[i] << " ";
            cout << "\n";
            for (int i = 0; i < cnt2; ++i)
                cout << c[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}
