//author@nowadays - 2021-04-27  22:25:09
#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

bool check(int n, int m, vector<vector<int>> a, const vector<vector<int>>& b) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (b[i][j] == 1) {
                for (int it = 0; it < 4; ++it) {
                    int x = dx[it] + i;
                    int y = dy[it] + j;
                    if (1 <= x && x <= n && 1 <= y && y <= m) {
                        a[x][y] --;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    ifstream test_in(argv[1]);    /* This stream reads from test's input file   */
    ifstream test_out(argv[2]);   /* This stream reads from test's output file  */
    ifstream user_out(argv[3]);   /* This stream reads from user's output file  */
    int n, m;
    test_in >> n >> m;
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            test_in >> a[i][j];
        }
    }
    vector<vector<int>> b(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            user_out >> b[i][j];
        }
    }
    if (check(n, m, a, b)) {
        return 0;
    }
    return 1;
}