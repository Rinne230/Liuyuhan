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
const ll maxn = 3e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

struct tnode{
    int l, r, mins;
};

struct setment_tree
{
    tnode t[maxn << 2];
    int leaf[maxn];
    void buildt(int rt, int l, int r){
        t[rt].l = l;
        t[rt].r = r;
        if(l == r){
            leaf[l] = rt;
            t[rt].mins = 0;
        }else{
            int mid = (l + r) >> 1;
            buildt(rt << 1, l, mid);
            buildt(rt << 1 | 1, mid + 1, r);
        }
    }
    void change_leaf(int pos, int val){
        int rt = leaf[pos];
        t[rt].mins = val;
        rt >>= 1;
        while(rt){
            t[rt].mins = min(t[rt << 1].mins, t[rt << 1 | 1].mins);
            rt >>= 1;
        }
        return;
    }
    int go(int L){
        int rt = 1;
        while (t[rt].l != t[rt].r){
            if(t[rt << 1].mins < L){
                rt = rt << 1;
            }else{
                rt = rt << 1 | 1;
            }
        }
        return t[rt].l - 1;
    }
};

setment_tree ST;


void solve(){

}

signed main(){
    ios;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}