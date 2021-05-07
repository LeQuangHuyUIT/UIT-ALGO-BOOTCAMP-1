//author@nowadays - 2021-05-06  20:26:31
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000007 // 1e7 + 7

int smallestFactor[MAXN];

void eratos() {
    for (int i = 0; i < MAXN; ++i) {
        smallestFactor[i] = i;
    }
    for (int i = 2; i * i < MAXN; ++i) {
        if (smallestFactor[i] == i) {
            for (int j = i + i; j < MAXN; j += i) {
                if (smallestFactor[j] == j) {
                    smallestFactor[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        set<int> unique;
        while (a != 1) {
            unique.insert(smallestFactor[a]);
            a /= smallestFactor[a];
        }
        while (b != 1) {
            unique.insert(smallestFactor[b]);
            b /= smallestFactor[b];
        }
        cout << unique.size() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    eratos();
    solve();
    return 0;
}