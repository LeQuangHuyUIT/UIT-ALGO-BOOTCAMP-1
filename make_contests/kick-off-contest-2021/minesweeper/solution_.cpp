//author@nowadays - 2021-04-28  10:53:24
#include <bits/stdc++.h>
using namespace std;

#define MAXN 110 
typedef vector<vector<int>> vec2D;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m;
vec2D a(MAXN, vector<int>(MAXN, 0));
vec2D b(MAXN, vector<int>(MAXN, 0));
vec2D tmp(MAXN, vector<int>(MAXN, 0));
vec2D ans(MAXN, vector<int>(MAXN, 0));

bool exist = false;
bool rev = false;

void apply(const vec2D& source, vec2D& dest, bool rev = false) {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            dest[i][j] = rev ? source[j][i] : source[i][j];
        }
    }
}

void add(int x, int y, int value) {
    if (value == -1) {
        b[x][y] = 1;
    } else {
        b[x][y] = 0;
    }
    for (int i = 0; i < 4; ++i) {
        a[x + dx[i]][y + dy[i]] += value;
    }
}

bool try_commit(int x, int y) {
    while (x <= n && y > 1) {
        if (a[x - 1][y] != 0 && a[x - 1][y] != 1) {
            return false;
        }
        add(x, y, -a[x - 1][y]);
        ++x;
        --y;
    }
    return a[x - 1][y] == 0;
}

void rollback(int x, int y) {
    while (x <= n && y > 1) {
        add(x, y, b[x][y]);
        ++x;
        --y;
    }
}
// guarantee: n <= m 
void back(int k) {
    if (exist) {
        return;
    }
    if (k == 1) {
        back(k + 1);
        add(1, 1, -1);
        back(k + 1);
        add(1, 1, +1);
        return;
    }
    if (k > m) {
        bool ok = true;
        for (int i = 2; i <= n; ++i) {
            if (!try_commit(i, m)) {
                ok = false;
                break;
            }
        }
        ok = ok & (a[n][m] == 0);
        if (ok) {
            exist = true;
            return (void) apply(b, ans);
        } 
        for (int i = 2; i <= n; ++i) {
            rollback(i, m);
        } 
        return;
    }
    for (int im = 0; im < 2; ++im) {
        add(1, k, -im);
        for (int in = 0; in < 2 - (k > n ? 1 : 0); ++in) {
            add(k, 1, -in);
            if (try_commit(2, k - 1)) {
                back(k + 1);
            }
            rollback(2, k - 1);
            add(k, 1, +in);
        }
        add(1, k, +im);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> tmp[i][j];
            }
        }
        if (n > m) {
            swap(n, m);
            rev = true;
        } 
        apply(tmp, a, rev);
    }
    back(1);
    if (exist) {    
        if (rev) {
            swap(n, m);
        }
        apply(ans, tmp, rev);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << tmp[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "NO_SOLUTION\n";
    }
    return 0;
}