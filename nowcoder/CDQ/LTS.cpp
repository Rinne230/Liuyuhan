#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, x, dp[MAXN], a[MAXN], ans;
pair<int, int> temp[MAXN][20]; //<val,pos>
bool cmp(const pair<int, int> &A, const pair<int, int> &B, const int &type)
{
    return type ? A.first != B.first ? A.first > B.first : A.second < B.second : A.first != B.first ? A.first < B.first
                                                                                                    : A.second > B.second;
}
void mergeSort(int l, int r, int deep, const int &cmptype)
{
    if (l == r)
    {
        temp[l][deep].first = a[l];
        temp[l][deep].second = l;
        return;
    }
    int mid = (l + r) >> 1;
    mergeSort(l, mid, deep + 1, cmptype);
    mergeSort(mid + 1, r, deep + 1, cmptype);
    int p1 = l, p2 = mid + 1;
    while (p1 <= mid && p2 <= r)
    {
        if (cmp(temp[p1][deep + 1], temp[p2][deep + 1], cmptype))
        {
            temp[l++][deep] = temp[p1++][deep + 1];
        }
        else
        {
            temp[l++][deep] = temp[p2++][deep + 1];
        }
    }
    while (p1 <= mid)
    {
        temp[l++][deep] = temp[p1++][deep + 1];
    }
    while (p2 <= r)
    {
        temp[l++][deep] = temp[p2++][deep + 1];
    }
}
void cdqDivAlgorithm(int l, int r, int deep, const int &cmptype)
{
    if (l == r)
    {
        dp[l] = max(dp[l], 1);
        ans = max(ans, dp[l]);
        return;
    }
    int mid = (l + r) >> 1;
    cdqDivAlgorithm(l, mid, deep + 1, cmptype);
    int p1 = l, p2 = mid + 1, premax = 0;
    while (p1 <= mid && p2 <= r)
    {
        if (cmp(temp[p1][deep + 1], temp[p2][deep + 1], cmptype))
        {
            premax = max(premax, dp[temp[p1++][deep + 1].second]);
        }
        else
        {
            dp[temp[p2][deep + 1].second] = max(premax + 1, dp[temp[p2][deep + 1].second]);
            p2++;
        }
    }
    while (p2 <= r)
    {
        dp[temp[p2][deep + 1].second] = max(premax + 1, dp[temp[p2][deep + 1].second]);
        p2++;
    }
    cdqDivAlgorithm(mid + 1, r, deep + 1, cmptype);
}
int main()
{
    while (scanf("%d", &x) != EOF)
        a[++n] = x;
    mergeSort(1, n, 0, 1);
    cdqDivAlgorithm(1, n, 0, 1);
    printf("%d\n", ans);
    memset(dp, 0, sizeof(dp));
    ans = 0;
    mergeSort(1, n, 0, 0);
    cdqDivAlgorithm(1, n, 0, 0);
    printf("%d\n", ans);
    return 0;
}
