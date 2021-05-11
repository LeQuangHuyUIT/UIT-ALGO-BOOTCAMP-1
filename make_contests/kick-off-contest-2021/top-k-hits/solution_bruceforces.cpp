//author@nowadays - 2021-04-27  22:33:34
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long long> score(n + 1, 0);
    while (q--) {
        char type;
        cin >> type;
        if (type == '1') {
            int l, r, v;
            cin >> l >> r >> v;
            for (int i = l; i <= r; ++i) {
                score[i] += v;
            }
        } else {
            int k;
            cin >> k;
            set<pair<long long, int>, greater<pair<long long, int>>> s;
            for (int i = 1; i <= n; ++i) {
                s.insert(make_pair(score[i], i));
                while ((int)s.size() > k) {
                    s.erase(*s.rbegin());
                }
            }
            for (auto i: s) {
                cout << i.second << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}