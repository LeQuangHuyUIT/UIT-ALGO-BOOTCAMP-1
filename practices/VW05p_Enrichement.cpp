//author@nowadays - 2021-05-08  10:00:52
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    assert(3 <= n && 3 <= m && n * m <= 1000000);
    int ans = numeric_limits<int>::max();
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = 1; j <= m - 2; ++j) {
            int tmp = 0;
            for (int dx = 0; dx < 3; ++dx) {
                for (int dy = 0; dy < 3; ++dy) {
                    tmp += a[i + dx][j + dy];
                }
            } 
            ans = min(ans, tmp);
        }
    }
    cout << ans << "\n";
    return 0;
}