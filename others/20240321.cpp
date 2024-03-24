#include <bits/stdc++.h>
#include <Eigen/Dense>
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
using ll = long long;
using ull = unsigned long long;
using db = long double;
const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll inf32 = 1e9;
const ll inf64 = 1e18;
const db eps = 1e-5;
const ll MaxITER = 1e3 + 10;
vector<vector<db>> process[5];

void printIter(vector<db> x, string Name)
{
    cout << Name << ":\n";
    cout << "迭代次数: " << fixed << setprecision(0) << x[0] << endl;
    if (x[0] > MaxITER)
    {
        cout << "迭代次数超过上限" << endl;
        return;
    }
    for (int i = 1; i < x.size(); ++i)
    {
        cout << fixed << setprecision(5) << x[i] << " \n"[i == x.size() - 1];
    }
}

vector<db> J(vector<vector<db>> A, vector<db> b)
{
    int n = b.size() - 1;
    vector<db> x(n + 1);
    int cnt = 0;
    while (1)
    {
        cnt++;
        vector<db> new_x(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            new_x[i] = b[i] / A[i][i];
            for (int j = 1; j <= n; ++j)
            {
                if (i != j)
                {
                    new_x[i] = new_x[i] - A[i][j] / A[i][i] * x[j];
                }
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (abs(new_x[i] - x[i]) > eps)
            {
                flag = false;
                break;
            }
        }
        if (flag || cnt > MaxITER)
        {
            x[0] = cnt;
            break;
        }
        x = new_x;
        process[1].push_back(x);
    }
    return x;
}

vector<db> GS(vector<vector<db>> A, vector<db> b)
{
    int n = b.size() - 1;
    vector<db> x(n + 1);
    int cnt = 0;
    while (1)
    {
        cnt++;
        auto x1 = x;
        for (int i = 1; i <= n; ++i)
        {
            x[i] = b[i] / A[i][i];
            for (int j = 1; j <= n; ++j)
            {
                if (i != j)
                {
                    x[i] = x[i] - A[i][j] / A[i][i] * x[j];
                }
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (abs(x[i] - x1[i]) > eps)
            {
                flag = false;
                break;
            }
        }
        if (flag || cnt > MaxITER)
        {
            x[0] = cnt;
            break;
        }
        process[2].push_back(x);
    }
    return x;
}

vector<db> CG(vector<vector<db>> A, vector<db> b)
{
    int n = b.size() - 1;
    vector<db> x(n + 1);
    vector<db> r(n + 1);
    vector<db> p(n + 1);
    vector<db> Ap(n + 1);
    db alpha, beta, r_norm, r_norm0;
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
        r[i] = b[i];
        p[i] = r[i];
    }
    r_norm0 = 0;
    for (int i = 1; i <= n; i++)
    {
        r_norm0 += r[i] * r[i];
    }
    r_norm0 = sqrt(r_norm0);
    int cnt = 0;
    while (1)
    {
        cnt++;
        for (int i = 1; i <= n; i++)
        {
            Ap[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                Ap[i] += A[i][j] * p[j];
            }
        }
        db pAp = 0;
        for (int i = 1; i <= n; i++)
        {
            pAp += p[i] * Ap[i];
        }
        alpha = 0;
        for (int i = 1; i <= n; i++)
        {
            alpha += r[i] * r[i];
        }
        alpha /= pAp;
        for (int i = 1; i <= n; i++)
        {
            x[i] += alpha * p[i];
            r[i] -= alpha * Ap[i];
        }
        r_norm = 0;
        for (int i = 1; i <= n; i++)
        {
            r_norm += r[i] * r[i];
        }
        r_norm = sqrt(r_norm);
        if (r_norm / r_norm0 < eps || cnt > MaxITER)
        {
            x[0] = cnt;
            break;
        }
        beta = 0;
        for (int i = 1; i <= n; i++)
        {
            beta += r[i] * r[i];
        }
        beta /= alpha;
        for (int i = 1; i <= n; i++)
        {
            p[i] = r[i] + beta;
        }
        process[3].push_back(x);
    }
    return x;
}

vector<db> SOR(vector<vector<db>> A, vector<db> b)
{
    int n = b.size() - 1;
    vector<db> x(n + 1);
    db w = 1.025;
    int cnt = 0;
    while (1)
    {
        cnt++;
        auto x1 = x;
        for (int i = 1; i <= n; ++i)
        {
            x[i] = b[i] / A[i][i];
            for (int j = 1; j <= n; ++j)
            {
                if (i != j)
                {
                    x[i] = x[i] - A[i][j] / A[i][i] * x[j];
                }
            }
            x[i] = w * x[i] + (1 - w) * x1[i];
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (abs(x[i] - x1[i]) > eps)
            {
                flag = false;
                break;
            }
        }
        if (flag || cnt > MaxITER)
        {
            x[0] = cnt;
            break;
        }
        process[4].push_back(x);
    }
    return x;
}

int Gauss(vector<vector<db>> A, vector<db> b)
{
    int n = b.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        int maxx = i;
        for (int j = 1; j <= n; j++)
        {
            if (abs(A[j][j]) > eps && j < i)
                continue;
            if (abs(A[j][i]) > abs(A[maxx][i]))
            {
                maxx = j;
            }
        }
        for (int j = 1; j <= n; j++)
            swap(A[maxx][j], A[i][j]);
        swap(b[maxx], b[i]);
        if (abs(A[i][i]) <= eps)
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            double delta = A[j][i] / A[i][i];
            for (int k = i; k <= n; k++)
            {
                A[j][k] -= delta * A[i][k];
            }
            b[j] -= delta * b[i];
        }
    }
    int key = 1;
    for (int i = 1; i <= n; i++)
    {
        if (abs(A[i][i]) <= eps)
        {
            if (abs(b[i]) > eps)
                key = -1;
            else if (key != -1)
                key = 0;
        }
    }
    if (key == -1)
    {
        cout << "无解" << endl;
    }
    else if (key == 0)
    {
        cout << "无穷多解" << endl;
    }
    else
    {
        cout << "高斯消元:\n";
        for (int i = 1; i <= n; i++)
        {
            cout << fixed << setprecision(5) << b[i] / A[i][i] << " \n"[i == n];
        }
    }
    return key;
}

void Doolittle(vector<vector<db>> A, vector<db> b)
{
    vector<vector<db>> U(A.size(), vector<db>(A.size()));
    vector<vector<db>> L(A.size(), vector<db>(A.size()));
    vector<db> y(A.size());
    vector<db> x(A.size());
    int n = A.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            U[i][j] = A[i][j];
            for (int k = 1; k <= i - 1; k++)
            {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
        for (int j = i + 1; j <= n; j++)
        {
            L[j][i] = A[j][i];
            for (int k = 1; k <= i - 1; k++)
            {
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] /= U[i][i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        y[i] = b[i];
        for (int j = 1; j <= i - 1; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        x[i] = y[i];
        for (int j = i + 1; j <= n; j++)
        {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    cout << "Doolittle:\n";
    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(5) << x[i] << " ";
    cout << endl;
}

void Cholesky(vector<vector<db>> A, vector<db> b)
{
    vector<vector<db>> L(A.size(), vector<db>(A.size()));
    vector<db> y(A.size());
    vector<db> x(A.size());
    int n = A.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == j)
            {
                db sum = 0;
                for (int k = 1; k <= j - 1; k++)
                {
                    sum += L[j][k] * L[j][k];
                }
                L[j][j] = sqrt(A[j][j] - sum);
            }
            else
            {
                db sum = 0;
                for (int k = 1; k <= j - 1; k++)
                {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        y[i] = b[i];
        for (int j = 1; j <= i - 1; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }
    for (int i = n; i >= 1; i--)
    {
        x[i] = y[i];
        for (int j = i + 1; j <= n; j++)
        {
            x[i] -= L[j][i] * x[j];
        }
        x[i] /= L[i][i];
    }
    cout << "Cholesky:\n";
    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(5) << x[i] << " ";
    cout << endl;
}

vector<vector<db>> inv(vector<vector<db>> A) //高斯消元法求矩阵的逆
{
    int n = A.size() - 1;
    vector<vector<db>> B(n + 1, vector<db>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        B[i][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int maxx = i;
        for (int j = 1; j <= n; j++)
        {
            if (abs(A[j][j]) > eps && j < i)
                continue;
            if (abs(A[j][i]) > abs(A[maxx][i]))
            {
                maxx = j;
            }
        }
        for (int j = 1; j <= n; j++)
            swap(A[maxx][j], A[i][j]);
        swap(B[maxx], B[i]);
        if (abs(A[i][i]) <= eps)
            continue;
        db delta = 1.0 / A[i][i];
        for (int j = 1; j <= n; j++)
        {
            A[i][j] *= delta;
            B[i][j] *= delta;
        }
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            delta = A[j][i];
            for (int k = 1; k <= n; k++)
            {
                A[j][k] -= delta * A[i][k];
                B[j][k] -= delta * B[i][k];
            }
        }
    }
    return B;
}

int cond1(vector<vector<db>> A, vector<vector<db>> B) // 1-条件数
{
    int n = A.size() - 1;
    db ans = 0;
    for (int i = 1; i <= n; i++)
    {
        db sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += abs(A[i][j]);
        }
        ans = max(ans, sum);
    }
    db ans1 = 0;
    for (int i = 1; i <= n; i++)
    {
        db sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += abs(B[i][j]);
        }
        ans1 = max(ans1, sum);
    }
    return ans * ans1;
}

int condinf(vector<vector<db>> A, vector<vector<db>> B) // 无穷条件数
{
    int n = A.size() - 1;
    db ans = 0;
    for (int i = 1; i <= n; i++)
    {
        db sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += abs(A[j][i]);
        }
        ans = max(ans, sum);
    }
    db ans1 = 0;
    for (int i = 1; i <= n; i++)
    {
        db sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += abs(B[j][i]);
        }
        ans1 = max(ans1, sum);
    }
    return ans * ans1;
}

bool isSymmetric(vector<vector<db>> A) //对称
{ // 判断是否对称
    int n = A.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (abs(A[i][j] - A[j][i]) > eps)
            {
                return false;
            }
        }
    }
    return true;
}

bool isPositiveDefinite(vector<vector<db>> A) //正定
{
    int n = A.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        if (A[i][i] <= 0)
        {
            return false;
        }
    }
    return true;
}

db spectral_radius(vector<vector<db>> A) {
    Eigen::MatrixXd eigen_matrix(A.size(), A[0].size());
    for (int i = 0; i < A.size() - 1; i++)
        for (int j = 0; j < A[0].size() - 1; j++)
            eigen_matrix(i, j) = A[i + 1][j + 1];
    Eigen::EigenSolver<Eigen::MatrixXd> es(eigen_matrix);
    db spectral_radius = 0.0;
    for (int i = 0; i < es.eigenvalues().size(); ++i)
        spectral_radius = max(spectral_radius, (db)abs(es.eigenvalues()[i]));
    return spectral_radius;
}

void solve()
{
    int n;
    cin >> n;
    vector H(n + 1, vector<db>(n + 1));
    vector<db> b(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            H[i][j] = (i == j ? 1 : 1.0 / (i + j + 0.1 * (((i + j) % 2) ? -1 : 1) - 1));
        }
    for (int i = 1; i <= n; ++i)
        b[i] = 1.0;
    cout << "1-条件数: " << cond1(H, inv(H)) << endl;
    cout << "∞-条件数: " << condinf(H, inv(H)) << endl;
    cout << "谱半径: " << spectral_radius(H) << endl;
    if (isSymmetric(H) && isPositiveDefinite(H))
        cout << "该矩阵对称正定" << endl;
    else
        cout << "该矩阵非对称正定" << endl;
    auto x1 = J(H, b); // Jacobi
    printIter(x1, "Jacobi");
    auto x2 = GS(H, b); // Gauss-Seidel
    printIter(x2, "Gauss-Seidel");
    auto x3 = CG(H, b); // CG
    printIter(x3, "CG");
    auto x4 = SOR(H, b); // SOR
    printIter(x4, "SOR");
    int tim = clock();
    int key = Gauss(H, b); // 高斯消元
    int tim1 = clock();
    cout << "高斯消元时间: " << tim1 - tim << "ms" << endl;
    if (key == 1)
    {
        tim = clock();
        Doolittle(H, b); // Doolittle
        tim1 = clock();
        cout << "Doolittle时间: " << tim1 - tim << "ms" << endl;
        tim = clock();
        Cholesky(H, b);  // Cholesky
        tim1 = clock();
        cout << "Cholesky时间: " << tim1 - tim << "ms" << endl;
    }
    for (int i = 1; i <= 4; i++)
    {
        cout << "迭代过程" << i << ":\n";
        if (process[i].size() >= MaxITER)
        {
            cout << "迭代次数超过上限" << endl;
            continue;
        }
        for (auto x : process[i])
        {
            for (int j = 1; j <= n; j++)
            {
                cout << fixed << setprecision(5) << x[j] << ",\n"[j == n];
            }
        }
    }
}

signed main()
{
    ios;
    int t = 1;
    // cin >> t;
    freopen("./20240321.txt", "w", stdout);
    while (t--)
    {
        solve();
    }
    return 0;
}