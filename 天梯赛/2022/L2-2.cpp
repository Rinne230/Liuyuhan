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
const ll N = 1e6 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

int t[N];
string getTime(int x){
    int h = x / 3600;
    int m = x % 3600 / 60;
    int s = x % 60;
    string res;
    if (h < 10) res += "0";
    res += to_string(h);
    res += ":";
    if (m < 10) res += "0";
    res += to_string(m);
    res += ":";
    if (s < 10) res += "0";
    res += to_string(s);
    return res;
}
void solve(){
    int n;
    cin >> n;
    int st = 0, ed = 24 * 60 * 60;
    for (int i = 1; i <= n; ++i){
        string s1, s2;
        char c;
        cin >> s1 >> c >> s2;
        int h1 = (s1[0] - '0') * 10 + s1[1] - '0';
        int m1 = (s1[3] - '0') * 10 + s1[4] - '0';
        int se1 = (s1[6] - '0') * 10 + s1[7] - '0';
        
        int h2 = (s2[0] - '0') * 10 + s2[1] - '0';
        int m2 = (s2[3] - '0') * 10 + s2[4] - '0';
        int se2 = (s2[6] - '0') * 10 + s2[7] - '0';
        t[h1 * 3600 + m1 * 60 + se1]++;
        t[h2 * 3600 + m2 * 60 + se2]--;
    }
    for (int i = 1; i < ed; ++i) t[i] += t[i - 1];
    for (int i = st; i < ed; ++i){
        if (!t[i]){
            int j = i;
            while (j < ed - 1 && !t[j]) j++;
            cout << getTime(i) << " - " << getTime(j) << endl;
            i = j - 1;
        }
        if (i == ed - 2) break;
    }

}

signed main(){
    lyh;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}