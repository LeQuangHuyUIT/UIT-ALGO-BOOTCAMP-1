//author@nowadays - 2021-05-06  21:13:46
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long double>> matrix;

int n;

matrix operator * (const matrix& a, const matrix& b) {
    matrix c(n, vector<long double>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int t = 0; t < n; ++t) {
                c[i][j] += a[i][t] * b[t][j];
            }
        }
    }
    return c;
}

matrix binpow(matrix a, int m) {
    matrix ans(n, vector<long double>(n, 0));
    for (int i = 0; i < n; ++i) {
        ans[i][i] = 1;
    }
    while (m > 0) {
        if (m & 1) {
            ans = ans * a;
        }
        a = a * a;
        m >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int m;
    cin >> n >> m;
    matrix a(n, vector<long double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    a = binpow(a, m);
    cout << fixed << setprecision(4);
    for (int i = 0; i < n; ++i) {
        cout << a[0][i] << "\n";
    }
    return 0;
}