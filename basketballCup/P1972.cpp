#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

struct BIT{
	ll tr[maxn];
	int lowbit(int x){return x & -x;}
	void add(int p, ll x){
		for (; p < maxn; p += lowbit(p)) tr[p] += x;
	}
	ll query(int p){
		ll sum = 0;
		for (; p > 0; p -= lowbit(p))
			sum += tr[p];
		return sum;
	}
}Tr;

ll pre[maxn], ans[maxn];
void solve(){
	int n, m;
	cin >> n;
	vector<pll> pos;
	vector<tuple<int, int, int, int>> q;
	for (int i = 3; i <= n + 2; ++i){
		int a;
		cin >> a;
		pos.push_back({i, pre[a] ? pre[a] : 2}), pre[a] = i;
	}
	sort(pos.begin(), pos.end());
	cin >> m;
	for (int i = 1; i <= m; ++i){
		int l, r;
		cin >> l >> r;
		l += 2, r += 2;
		q.push_back({l - 1, 1, 1, i});
		q.push_back({l - 1, l - 1, -1, i});
		q.push_back({r, 1, -1, i});
		q.push_back({r, l - 1, 1, i});
	}
	sort(q.begin(), q.end());
    int cur = 0;
    for (auto [x, y, c, id] : q)
    {
        while (cur < n && pos[cur].first <= x)
            Tr.add(pos[cur++].second, 1);
        ans[id] += c * Tr.query(y);
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << endl;
}

int main(){
    ios;
    //freopen("sample.txt", "r", stdin);
    //freopen("resout.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}