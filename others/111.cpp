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
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define lyh ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

double solve(vi &nums1, vi &nums2){
    int n = nums1.size();
    int m = nums2.size();
    int k = (n + m - 1) / 2;
    if (n == 0 || m == 0) {
        if (n == 0) {
            if (m & 1) return nums2[m / 2];
            else return (nums2[m / 2] + nums2[m / 2 - 1]) / 2.0;
        } else {
            if (n & 1) return nums1[n / 2];
            else return (nums1[n / 2] + nums1[n / 2 - 1]) / 2.0;
        }
    }
    int l = 0, r = min(n - 1, k);
    while (l < r) {
        int mid = (l + r) / 2;
        if (k - mid - 1 >= m || nums1[mid] < nums2[k - mid - 1]) l = mid + 1;
        else r = mid;
    }
    
    int x1 = l;
    if (k - l - 1 >= m) x1 = -1 ;
    else if (k - l - 1 >= 0 && nums1[l] < nums2[k - l - 1]) x1 = -1;
    l = 0, r = min(m - 1, k);
    while (l < r) {
        int mid = (l + r) / 2;
        if (k - mid - 1 >= n || nums2[mid] < nums1[k - mid - 1]) l = mid + 1;
        else r = mid;
    }
    
    int x2 = l;
    if (k - l - 1 >= n) x2 = -1;
    else if (k - l - 1 >= 0 && nums2[l] < nums1[k - l - 1]) x2 = -1;
    if ((n + m) & 1){
        double ans = 10000000.0;
        if (x1 != -1) ans = min(ans, (double)nums1[x1]);
        if (x2 != -1) ans = min(ans, (double)nums2[x2]);
        return ans;
    }
    double ans = 10000000.0;
    if (x1 == -1){
        l = x2;
        if (l + 1 < m) ans = min(ans, (double)(nums2[l] + nums2[l + 1]) / 2.0);
        if (k - l < n) ans = min(ans, (double)(nums2[l] + nums1[k - l]) / 2.0);
    }else if (x2 == -1){
        l = x1;
        if (l + 1 < n) ans = min(ans, (double)(nums1[l] + nums1[l + 1]) / 2.0);
        if (k - l < m) ans = min(ans, (double)(nums1[l] + nums2[k - l]) / 2.0);
    }else{
        if (nums1[x1] < nums2[x2]) {
            if (x1 + 1 < n) ans = min(ans, (double)(nums1[x1 + 1] + nums1[x1]) / 2.0);
            if (k - x1 < m) ans = min(ans, (double)(nums1[x1] + nums2[k - x1]) / 2.0);
        }else{
            if (x2 + 1 < m) ans = min(ans, (double)(nums2[x2 + 1] + nums2[x2]) / 2.0);
            if (k - x2 < n) ans = min(ans, (double)(nums2[x2] + nums1[k - x2]) / 2.0);
        }
    }
    return ans;
}

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        rep(i, 0, n - 1) cin >> a[i];
        rep(i, 0, m - 1) cin >> b[i];
        cout << solve(a, b) << endl;
    }
    return 0;
}