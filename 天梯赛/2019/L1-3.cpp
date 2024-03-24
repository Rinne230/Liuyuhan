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
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

void solve(){
    string s;    
    getline(cin, s);
    vector<string> v1, v2;
    int ok = 1;
    int lst = 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == ' '){
            if (ok){
                v1.push_back(s.substr(lst, i - lst));
                lst = i + 1;
            }else{
                v2.push_back(s.substr(lst, i - lst));
                lst = i + 1;
            }
        }else if (s[i] == ','){
            ok = 0;
            if (i < 3 || s[i - 1] != 'g' || s[i - 2] != 'n' || s[i - 3] != 'o'){
                cout << "Skipped" << endl;
                return;
            }
            v1.push_back(s.substr(lst, i - lst));
            lst = i + 2;
            i++;
        }else if (s[i] == '.'){
            if (s[i - 1] != 'g' || s[i - 2] != 'n' || s[i - 3] != 'o'){
                cout << "Skipped" << endl;
                return;
            }
            v2.push_back(s.substr(lst, i - lst));
        }
    }
    v2[v2.size() - 1] = "zhong";
    v2[v2.size() - 2] = "ben";
    v2[v2.size() - 3] = "qiao";
    cout << v1[0];
    for (int i = 1; i < v1.size(); ++i){
        cout << " " << v1[i];
    }
    cout <<',';
    for (int i = 0; i < v2.size(); ++i){
        cout << " " << v2[i];
    }
    cout << '.' << endl;
}

signed main(){
    ios;
    int t = 1;
    cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }
    return 0;
}