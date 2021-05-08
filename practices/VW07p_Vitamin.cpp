//author@nowadays - 2021-05-08  10:45:12
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = a[n];
    for (int i = 2; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    vector<int> dp(m + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m - a[i]; ++j) {
            dp[j + a[i]] = min(dp[j + a[i]], dp[j] + i + (j == 0 ? 0 : 1));
        }
    }
    int ans = dp[m];
    if (m >= a[n]) {
        m -= a[n];
        for (int i = 1; m - l >= 0; ++i) {
            m -= l;
            ans = min(ans, dp[m] + n + i + (m == 0 ? 0 : 1));
        }
    }
    if (ans >= INF) {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}