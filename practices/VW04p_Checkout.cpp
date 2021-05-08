//author@nowadays - 2021-05-08  10:05:03
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    double d, a1, a2, v, t;
    cin >> d >> a1 >> a2 >> v >> t;

    double ans = -1;
    double lef = 0.0;
    double rig = v / a1;
    for (int iter = 0; iter < 1000; ++iter) {
        double t1 = (lef + rig) / 2;
        double v1 = a1 * t1;
        double s1 = a1 * t1 * t1 / 2;
        double t2 = v1 / a2;
        double s2 = a2 * t2 * t2 / 2;
        double s3 = d - s1 - s2;
        double t3 = s3 / v1;
        if (t3 < t) {
            rig = t1;
        } else {
            lef = t1;
            ans = t1 + t2 + t3;
        }
    }
    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}