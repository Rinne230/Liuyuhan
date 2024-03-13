// #include <bits/stdc++.h>
// #define endl '\n'
// #define pll pair<ll, ll>
// #define tll tuple<ll, ll, ll>
// #define vi vector<int>
// #define vl vector<ll>
// #define x first
// #define y second
// #define all(a) a.begin() + 1, a.end()
// #define int ll
// #define rep(i, j, k) for (int i = (j); i <= (k); i++)
// #define per(i, j, k) for (int i = (j); i >= (k); i--)
// #define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// using namespace std;
// typedef long long ll;
// const ll maxn = 2e5 + 10;
// const ll mod = 998244353;
// const ll inf32 = 1e9;
// const ll inf64 = 1e18;

// vector<vi> ans;
// map<ll, vi> mp;

// void init(int len, vi &res)
// {
//     int l = 1, r = 1;
//     for (int i = 1; i < len; ++i)
//         l *= 10;
//     r = l * 10 - 1;
//     mp.clear();
//     for (int i = 1; i * i <= r; ++i)
//     {
//         if (i * i < l)
//             continue;
//         vector<int> tmp;
//         int num = i * i;
//         while (num)
//         {
//             tmp.emplace_back(num % 10);
//             num /= 10;
//         }
//         sort(tmp.begin(), tmp.end());
//         int id = 0;
//         for (auto v : tmp)
//             id = id * 10 + v;
//         mp[id].emplace_back(i * i);
//     }
//     for (auto [id, vec] : mp)
//     {
//         if (vec.size() > res.size())
//             res = vec;
//     }
// }
// void solve()
// {
//     int n;
//     cin >> n;
//     ans.resize(12);
//     for (int i = 1; i <= 11; i += 2)
//     {
//         init(i, ans[i]);
//     }

//     cout << "vector<vector<ll>> ans={";
//     for (int i = 0; i < 12; ++i)
//     {
//         if (i % 2 == 0)
//         {
//             cout << "{},";
//             continue;
//         }
//         if (i < 11)
//             ans[i].resize(i);
//         else
//             ans[i].resize(100);
//         ll b = ans[i].back();
//         ans[i].pop_back();
//         cout << "{";
//         for (auto v : ans[i])
//             cout << v << ",";
//         cout << b << "}";
//         if (i < 11)
//             cout << ",";
//     }
//     cout << "};";
//     cout << endl;
// }

// signed main()
// {
//     ios;
//     int t = 1;
//     //cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

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
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;

vector<vi> ans = {{}, {1}, {}, {169, 196, 961}, {}, {10609, 16900, 19600, 61009, 90601}, {}, {1006009, 1060900, 1690000, 1960000, 6100900, 9006001, 9060100}, {}, {139854276, 152843769, 157326849, 215384976, 245893761, 254817369, 326597184, 361874529, 375468129}, {}, {10057482369, 10208475369, 10859307264, 12938607504, 13470852096, 13985427600, 14050783296, 14809673025, 15284376900, 15309607824, 15732684900, 16203507849, 16375809024, 17049830625, 17206093584, 17345680209, 17530289604, 17689532004, 18497360025, 20134758609, 20635897104, 20851937604, 20859736041, 20897015364, 21538497600, 21753890064, 23054170896, 23081509476, 24589376100, 25083907641, 25481736900, 25713084609, 25874009316, 25930016784, 25936780401, 26913058704, 27003691584, 27058934016, 27905368401, 28391576004, 28403709156, 29754180036, 30264517089, 30410825769, 30829741056, 30902475681, 31807652409, 32059618704, 32659718400, 34900217856, 35042716809, 35047209681, 35249687001, 35600897124, 35907218064, 36108740529, 36187452900, 36805271409, 37018529604, 37019684025, 37546812900, 37984061025, 38294576100, 38417960025, 38529764100, 39207564081, 40053217689, 40305782169, 40935810276, 41273985600, 41602537089, 41753200896, 43678910025, 45038601729, 45090823716, 45231080976, 45390728601, 48621573009, 48702310596, 49370618025, 50201987364, 50704681329, 51072836049, 52381476900, 52908740361, 52987436100, 53721968400, 53968400721, 54800937216, 54807960321, 54938672100, 57408639201, 58743216900, 58932417600, 59608734201, 59736248100, 60054893721, 61538724900, 62017435089, 62795348100}};
void solve()
{
    int n;
    cin >> n;
    int p = min(n, 11ll);
    for (int i = 0; i < n; ++i){
        cout << ans[p][i];
        for (int j = 11; j < n; ++j) cout << 0;
        cout << endl;
    }
}

signed main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}