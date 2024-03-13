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
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

bool check(string s){//判断是否只有一个O
    int cnt = 0;
    for(auto i : s){
        cnt += i=='O';
    }
    return cnt == 1;
}

map<string, int> mp;
bool dfs(string s){
    if(mp.count(s))return mp[s];
    if(check(s)){//当当前状态只有一个O时标记为必败态
        mp[s] = false;
        return false;
    }
    //放置一个
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == 'O'){
            string tmp = s;
            tmp[i] = 'X';
            if(dfs(tmp) == false){
                mp[s] = true;
                return true;
            }
        }
    }
    //放置两个
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == 'O' && s[i+1] == 'O' && i != 3){
            string tmp = s;
            tmp[i] = 'X';
            tmp[i+1] = 'X';
            if(dfs(tmp) == false){
                mp[s] = true;
                return true;
            }
        }
    }
    mp[s] = false;
    return false;
}

void solve(){
    string s;
    cin >> s;
    mp.clear();
    cout << (dfs(s) ? "YES" : "NO") << endl;
}
signed main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}