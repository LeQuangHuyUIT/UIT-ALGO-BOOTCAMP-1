//author@nowadays - 2021-04-27  22:25:09
#include <bits/stdc++.h>
using namespace std;

bool check(int n, const vector<int>& a, int x, vector<int> ans) {
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if ((int) ans.size() != x) {
        return false;
    }
    vector<bool> used(n, true);
    for (int i = 0; i < x; ++i) {
        used[ans[i] - 1] = false;
    }
    vector<int> na; 
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            na.push_back(a[i]);
        }
    }
    n = (int) na.size();
    int m = 0;
    for (auto i: na) {
        m += i;
    }
    if (m % 2) {
        return true;
    }
    vector<bool> dp(m + 1, false);
    dp[0] = true;
    for (auto v: na) {
        for (int i = m - v; i >= 0; --i) {
            dp[i + v] = dp[i + v] | dp[i];
        }
    }
    if (dp[m / 2]) {
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    ifstream test_in(argv[1]);    /* This stream reads from test's input file   */
    ifstream test_out(argv[2]);   /* This stream reads from test's output file  */
    ifstream user_out(argv[3]);   /* This stream reads from user's output file  */
    int n;
    test_in >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        test_in >> a[i];
    }
    
    string test_sx;
    string user_sx;
    test_out >> test_sx;
    user_out >> user_sx;
    if (test_sx != user_sx) {
        return 1;
    }
    if (user_sx != "0" && user_sx != "1") {
        return 1;
    }
    int x = stoi(user_sx);
    vector<int> ans(x);
    for (int i = 0; i < x; ++i) {
        user_out >> ans[i];
    }
    if (check(n, a, x, ans)) {
        return 0;
    }
    return 1;
}