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

void solve(){
    int n, x, pos;
    cin >> n >> x;
    vi p(n + 1), visl(n + 1), visr(n + 1);
    rep(i, 1, n) {
        cin >> p[i];
        if (p[i] == x){
            pos = i;
        }
    }
    int l = 1, r = n + 1;
    while (r - l != 1){
        int mid = (l + r) >> 1;
        if (p[mid] <= x){
            visl[mid] = 1;
            l = mid;
        }else{
            visr[mid] = 1;
            r = mid;
        }
    }
    if (p[l] == x) {cout << 0 << endl; return;}
    //cout << visl[l] << " " << visr[l] << endl;
    if (visl[l]){
        if (visl[pos] || !visr[pos]){
            cout << 1 << endl;
            cout << pos << " " << l << endl;
            swap(p[pos], p[l]);
        }else if (visr[pos]){
            cout << 2 << endl;
            int idx = 0;
            for (int i = 1; i <= n; ++i){
                if (!visl[i] && !visr[i] && p[i] > x){
                    idx = i;
                    break;
                }
            }
            cout << pos << " " << idx << endl;
            swap(p[pos], p[idx]);
            cout << l << " " << idx << endl;
            swap(p[l], p[idx]);
        }
    }else{
        if (visl[pos]){
            if (p[l] < x){
                cout << 1 << endl;
                cout << pos << " " << l << endl;
                swap(p[pos], p[l]);
            }else{
                cout << 2 << endl;
                int idx = 0;
                for (int i = 1; i <= n; ++i){
                    if (!visl[i] && !visr[i] && p[i] < x){
                        idx = i;
                        break;
                    }
                }
                cout << pos << " " << idx << endl;
                swap(p[pos], p[idx]);
                cout << l << " " << idx << endl;
                swap(p[l], p[idx]);
            }
        }else{
            cout << 1 << endl;
            cout << pos << " " << l << endl;
            swap(p[pos], p[l]);
        }
    }
    int lc = 1, rc = n + 1;
    while (rc - lc != 1){
        int mid = (lc + rc) >> 1;
        if (p[mid] <= x){
            lc = mid;
        }else{
            rc = mid;
        }
    }
    //if (p[lc] == x) {cout << "ok" << endl; return;}
}

signed main(){
    lyh;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}