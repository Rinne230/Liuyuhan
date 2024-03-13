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
using i64 = long long;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

typedef __int128 i128;

i128 read()
{
    i128 x = 0;
    bool f = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? -x : x;
}
 
inline void write(i128 x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
 
i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
 
void solve()
{
    i64 p1, r1;  // 定义两个64位整数p1和r1，分别表示第一个同余方程的模数和余数
    int n;  // 定义整数n，表示同余方程的数量
    cin >> n;  // 从输入中读取n
    cin >> p1 >> r1;  // 从输入中读取第一个同余方程的模数和余数
    bool flag = false;  // 定义一个标志变量flag，用于标记是否存在无解的情况

    for (int i = 0; i < n - 1; i++)  // 对于剩下的n-1个同余方程
    {
        i64 p2, r2;  // 定义两个64位整数p2和r2，分别表示当前同余方程的模数和余数
        cin >> p2 >> r2;  // 从输入中读取当前同余方程的模数和余数
        if (flag == true)  // 如果已经发现存在无解的情况，则跳过剩下的处理
            continue;
        i64 y1, y2;  // 定义两个64位整数y1和y2，用于存储扩展欧几里得算法的结果
        i64 d = exgcd(p1, p2, y1, y2);  // 调用扩展欧几里得算法，计算p1和p2的最大公约数d，并得到y1和y2的值
        if ((r2 - r1) % d != 0)  // 如果(r2 - r1)不能被d整除，则说明这两个同余方程无解
            flag = true;  // 设置flag为true，表示存在无解的情况
        y1 = (i128)y1 * (r2 - r1) / d % (p2 / d);  // 计算新的y1的值
        i64 lc = (i128)p1 * p2 / d;  // 计算p1和p2的最小公倍数lc
        r1 = (((i128)p1 * y1 % lc + r1) % lc + lc) % lc;  // 计算新的r1的值
        p1 = lc;  // 更新p1的值为lc
    }
    if (flag)  // 如果存在无解的情况
        cout << -1 << endl;  // 输出-1
    else  // 否则
        cout << r1 << endl;  // 输出最终的结果r1
}

signed main()
{
    ios;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}