#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)

const int inf = 1e18;
const int N = 3e5 + 200;

int n;                      // 树的节点个数
int a[N];                   // 每个节点的颜色
int pre[N];                 // 记录子树中上一个颜色为i的节点编号
vector<int> mp[N];          // 存树
vector<int> nxt[N];         // 记录每个点的所有子树中最近的与之同颜色点的位置
int in[N], out[N], tot = 0; // 记录dfs序
int ans = 1;                // 记录答案，最小值为1
int cnt = 0;                // 记录当前的u到节点1的路径颜色数
// 下为线段树模板
int tag[4 * N];
int max1[4 * N];

void push_up(int p)
{
    max1[p] = max(max1[ls(p)], max1[rs(p)]);
}

void build(int p, int l, int r)
{
    if (l == r)
    {
        tag[p] = max1[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}

void push_down(int p)
{
    if (!tag[p])
        return;
    tag[ls(p)] += tag[p];
    max1[ls(p)] += tag[p];
    tag[rs(p)] += tag[p];
    max1[rs(p)] += tag[p];
    tag[p] = 0;
}

void update(int nl, int nr, int k, int p = 1, int l = 1, int r = n)
{
    if (nl <= l && r <= nr)
    {
        tag[p] += k;
        max1[p] += k;
        return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if (nl <= mid)
        update(nl, nr, k, ls(p), l, mid);
    if (nr > mid)
        update(nl, nr, k, rs(p), mid + 1, r);
    push_up(p);
}

int querymax(int x, int y, int l = 1, int r = n, int p = 1)
{
    int res = -inf;
    if (x > y)
        return 0;
    if (x <= l && y >= r)
    {
        return max1[p];
    }
    int mid = (l + r) >> 1;
    push_down(p);
    if (x <= mid)
        res = max(res, querymax(x, y, l, mid, ls(p)));
    if (y > mid)
        res = max(res, querymax(x, y, mid + 1, r, rs(p)));
    return res;
}
// 上为线段树模板

void dfs1(int u)
{
    in[u] = ++tot;       // 记录进入u的时间戳
    int now = pre[a[u]]; // 记录当前的pre值
    if (!now)
        ++cnt; // 如果路径上没有出现这个颜色，当前路径总颜色数+1
    else
        nxt[now].push_back(u); // 出现过了！那就存进nxt里
    pre[a[u]] = u;             // 更新pre值
    update(tot, tot, cnt);     // 在线段树上更新当前点到1路径上的颜色数
    for (auto v : mp[u])
    {
        dfs1(v); // 递归
    }
    // 回溯
    pre[a[u]] = now; // 将pre也回溯成原值
    if (!now)
        --cnt;    // 回溯了，所以把这个颜色减去
    out[u] = tot; // 在回溯时，记录离开u的时间戳
}

void dfs2(int u)
{
    int mx = 1; // 用来记录遍历过的儿子节点的子树中的最大值，初值设为1，这样u只有一棵子树时直接×1
    for (auto v : mp[u])
    {                                      // 枚举lca为u,遍历其所有儿子节点v
        int mx1 = querymax(in[v], out[v]); // 找到子树中的最大值
        ans = max(ans, mx1 * mx);          // 更新答案
        mx = max(mx1, mx);                 // 更新mx
    }
    update(in[u], out[u], -1); // 在算u的孩子节点之前，先把整棵子树全都减1，消除u的影响
    for (auto v : nxt[u]) 
    {
        update(in[v], out[v], 1); // 如果只有上面的update，u的孩子节点中仍有和u同色的节点，会对答案造成影响，可以直接给u的所有子树里下一次出现的与u同色的v节点加1来抵消这个影响
    }
    for (auto v : mp[u])
    {
        dfs2(v); // 继续递归
    }
}

void init(int n)
{ // 多测初始化
    ans = 1;
    tot = cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        mp[i].clear();
        nxt[i].clear();
    }
}

void solve()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    dfs1(1);
    dfs2(1);
    cout << ans << endl;
    init(n);
}

signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}