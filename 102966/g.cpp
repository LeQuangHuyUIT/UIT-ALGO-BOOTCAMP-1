//author@nowadays - 2021-05-06  20:39:53
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long long l;
    int g;
    cin >> l >> g;
    long long ans = 0;
    while (g--) {
        long long p;
        char type;
        cin >> p >> type;
        if (type == '0') {
            ans = max(ans, p);
        } else {
            ans = max(ans, l - p);
        }
    }
    cout << ans << "\n";
    return 0;
}