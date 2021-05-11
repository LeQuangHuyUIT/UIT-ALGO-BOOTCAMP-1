//author@nowadays - 2021-04-27  22:25:09
#include <bits/stdc++.h>
using namespace std;

bool check(int n, int s, const string& ans) {
    int t = n * (n + 1) / 2;
    if (t < s || (t - s) % 2 == 1) {
        return ans == "NO_SOLUTION";
    }
    if ((int) ans.size() != n) {
        return false;
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (ans[i] == '+') {
            cur += (i + 1);
            continue;
        }
        if (ans[i] == '-') {
            cur -= (i + 1);
            continue;
        }
        return false;
    }
    return cur == s;
}

int main(int argc, char* argv[]) {
    ifstream test_in(argv[1]);    /* This stream reads from test's input file   */
    ifstream test_out(argv[2]);   /* This stream reads from test's output file  */
    ifstream user_out(argv[3]);   /* This stream reads from user's output file  */
    int n, k;
    test_in >> n >> k;
    string test, user;
    test_out >> test;
    user_out >> user;
    if (check(n, k, user)) {
        return 0;
    }
    return 1;
}