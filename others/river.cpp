#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define pii pair<int, int>
#define tii tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define x first
#define y second
#define WA cout << "NO" << endl
#define AC cout << "YES" << endl
#define all(a) a.begin() + 1, a.end()
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define int ll
#define ios ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
typedef long long ll;
using namespace std;
const ll N = 5;
const ll mod = 998244353;
const ll inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;

int d[5][2] = {{0, 1}, {0, 2}, {1, 0}, {2, 0}, {1, 1}}; //船运输方式 名称与模型建立部分对应
void solve(){
	int n; //人数
	cin >> n;
	vector<vi> S(n + 1, vi(n + 1, 0)); //状态
	rep(i, 0, n)
		rep(j, 0, n)
			if (i == 0 || i == n || i == j)
				S[i][j] = 1; //为1代表合法的岸人数状态
	vector<pll> path; //路径
	auto check = [&](int x, int y) -> bool{
		return (x >= 0 && x <= n) && (y >= 0 && y <= n);
	};
    int mn = 1e3, cnt = 0, t = 1;
    vector<pll> ans;
	function<void(int, int, int, int)> dfs = [&](int x, int y, int lstd, int dep) { //左边 lstd:上一次选择的方案
        if (cnt == 5 || dep >= mn) return;
		if(x == 0 && y == 0){
            cnt++;
            if (path.size() < mn){ //最少的步数
                mn = path.size();
                ans = path;
            }
            return;
		}
		for (int i = 0; i < 5; ++i){
            int tx, ty;
			if (t & 1) tx = x - d[i][0], ty = y - d[i][1];
			else tx = x + d[i][0], ty = y + d[i][1];
            if (check(tx, ty)){
                if (S[tx][ty] && lstd != i){ // 防止往回走
                    path.push_back({tx, ty});
                    t++;
                    dfs(tx, ty, i, dep + 1);
                    path.pop_back(); //回溯
                    t--;
			    }
		    }
		}
	};
    path.push_back({n, n}); //传入起点
	dfs(n, n, -1, 1);
    int idx = 1;
    for (auto [u, v] : ans) cout << idx++ << " : " << u << " " << v << endl;
    if (ans.size() == 0) cout << "No Solution" << endl;
}

signed main(){
    std::ios;
    int t = 1;
    //std::cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

