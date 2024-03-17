#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 5e4 + 10, M = 1e6 + 7, X = 1e9 + 1;
int n, m;
struct node
{
    int x, y, r;
} b[N];
typedef long long ll;
ll h[M];        // 哈希数组
bool st[N];     // 判断是否访问过
int id[M], res; // id数组为哈希数组中key对应的地雷下标

ll get_hs(int x, int y)
{ // 得到每个坐标的哈希值
    return (ll)x * X + y;
}

int find(int x, int y)
{ // 找到该坐标被哈希数组存储的下标key
    ll hs = get_hs(x, y);
    int key = (hs % M + M) % M; // 映射到哈希数组内部
    // 如果该位置已经被占用并且不等于我们要求的哈希值，要在之后找到相应位置
    while (h[key] != -1 && h[key] != hs)
    {

        key++;
        if (key == M)
            key = 0; // 哈希表走到末尾，又从0开始
    }
    return key;
}

// 判断x1，y1为圆心，半径为r的圆是否包含x，y
bool check(int x1, int y1, int r, int x, int y)
{
    int d = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
    return d <= r * r;
}

void bfs(int pos)
{
    queue<int> q;
    q.push(pos);
    st[pos] = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        int x = b[t].x, y = b[t].y, r = b[t].r;
        for (int xx = x - r; xx <= x + r; xx++)
        { // 从(x-r, y-r)枚举到(x+r, y+r)
            for (int yy = y - r; yy <= y + r; yy++)
            {
                int key = find(xx, yy); // 找到该坐标点对应的哈希下标
                // 该点是不是地雷，有没有被访问过，能不能炸到
                if (id[key] && !st[id[key]] && check(x, y, r, xx, yy))
                {
                    int pos = id[key]; // 获得对应地雷编号
                    st[pos] = 1;
                    q.push(pos);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    int x, y, r;
    for (int i = 1; i <= n; i++)
    { // 读入地雷，存入哈希表
        cin >> x >> y >> r;
        b[i] = {x, y, r};
        int key = find(x, y); // 找到该坐标点对应的哈希下标
        if (h[key] == -1)
            h[key] = get_hs(x, y); // 如果哈希对应位置为空，则插入

        // id数组没有被标记或者找到了同一个坐标点更大半径的地雷
        if (!id[key] || b[id[key]].r < r)
        {
            id[key] = i;
        }
    }
    for (int i = 1; i <= m; i++)
    { // 枚举导弹
        cin >> x >> y >> r;
        for (int xx = x - r; xx <= x + r; xx++)
        {
            for (int yy = y - r; yy <= y + r; yy++)
            {
                int key = find(xx, yy);

                // 如果该点有地雷，没有被访问过，能被炸到
                if (id[key] && !st[id[key]] && check(x, y, r, xx, yy))
                    bfs(id[key]);
            }
        }
    }
    // 遍历每个地雷，看是否被标记
    for (int i = 1; i <= n; i++)
    {
        int key = find(b[i].x, b[i].y); // 获得坐标点对应哈希下标
        int pos = id[key];              // 哈希下标对应的地雷编号
        if (pos && st[pos])
            res++; // 如果有地雷并且被访问过
    }
    cout << res;
    return 0;
}
