//author@nowadays - 2021-05-06  20:34:29
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ans += x;
    }
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        ans -= x;
    }
    ans = min(0LL, ans);
    cout << -ans << "\n";
    return 0;
}