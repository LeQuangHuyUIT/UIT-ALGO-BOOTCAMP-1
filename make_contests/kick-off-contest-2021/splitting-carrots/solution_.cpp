//author@nowadays - 2021-04-28  10:38:38
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> a) {
    int n = (int) a.size();
    int m = 0;
    for (int i = 0; i < n; ++i) {
        m += a[i];
    }
    if (m % 2) {
        return vector<int>();
    }
    while (true) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (a[i] % 2 == 0 ? 1 : 0);
        }
        if (cnt != n) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            a[i] /= 2;
        }
        m /= 2;
    }
    vector<bool> dp(m + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = m - a[i]; j >= 0; --j) {
            if (dp[j]) {
                dp[j + a[i]] = true;
            }
        }
    }
    if (m % 2 || !dp[m / 2]) {
        return vector<int>();
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) {
            return vector<int>({i + 1});
        }
    }
    assert(false);
    return vector<int>();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ans = solve(a);
    cout << (int) ans.size() << "\n";
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}