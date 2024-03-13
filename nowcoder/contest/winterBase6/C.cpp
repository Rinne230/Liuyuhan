#include <bits/stdc++.h>

using namespace std;

int a[110];
int T, n, ans[10], r;
void sl()
{
    cin >> n;
    r = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = 45; i >= 1; i--)
    {
        while (n >= a[i])
            n -= a[i], ans[++r] = a[i];
    }
    if (r > 3)
        cout << -1 << endl;
    else
        for (int i = 1; i <= 3; i++)
            cout << ans[i] << " ";
    cout << endl;
}
int main()
{
    a[1] = 1;
    for (int i = 2; i <= 45; i++)
        a[i] = a[i - 1] + a[i - 2];
    cin >> T;
    while (T--)
        sl();
}