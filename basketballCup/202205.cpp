#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int N = 5e5 + 10;
int l[N], r[N], mx[N];
int a[N];
int f1[N], f2[N];
/*
f1[i]表示a[1~i]中以a[i]结尾的最长不下降子序列的长度
f2[i]表示a[i~n]中以a[i]开头的最长不下降子序列的长度
*/
vector<int> alls;
int find(int x)
{
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
void pushup(int id)
{
    mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
void build(int id, int L, int R)
{
    l[id] = L;
    r[id] = R;
    mx[id] = 0;
    if (L == R)
        return;
    int mid = L + R >> 1;
    build(id << 1, L, mid);
    build(id << 1 | 1, mid + 1, R);
    pushup(id);
}
void update_point(int id, int pos, int val)
{
    if (l[id] == r[id])
    {
        mx[id] = val;
        return;
    }
    int mid = l[id] + r[id] >> 1;
    if (pos <= mid)
        update_point(id << 1, pos, val);
    else
        update_point(id << 1 | 1, pos, val);
    pushup(id);
}
int query_interval(int id, int L, int R)
{
    if (l[id] >= L && r[id] <= R)
        return mx[id];
    int mid = l[id] + r[id] >> 1;
    int ans = 0;
    if (L <= mid)
        ans = max(ans, query_interval(id << 1, L, R));
    if (mid + 1 <= R)
        ans = max(ans, query_interval(id << 1 | 1, L, R));
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        alls.push_back(a[i]);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 1; i <= n; i++)
        a[i] = find(a[i]);
    build(1, 1, alls.size());
    for (int i = 1; i <= n; i++)
    {
        f1[i] = query_interval(1, 1, a[i]) + 1;
        update_point(1, a[i], f1[i]);
    }
    int ans = 0;
    build(1, 1, alls.size());
    for (int i = n; i >= 1; i--)
    {
        f2[i] = query_interval(1, a[i], alls.size()) + 1;
        update_point(1, a[i], f2[i]);
        if (i > k)
        {
            ans = max(ans, f1[i - k - 1] + k + query_interval(1, a[i - k - 1], alls.size()));
            ans = max(ans, k + f2[i]);
        }
        if (i + k <= n)
            ans = max(ans, k + f1[i]);
    }
    printf("%d\n", ans);
    return 0;
}