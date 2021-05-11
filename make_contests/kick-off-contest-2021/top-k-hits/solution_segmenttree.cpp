//author@nowadays - 2021-04-27  22:39:05
#include <bits/stdc++.h>
using namespace std;

#define MAX 150000 * 4 + 3
typedef vector<pair<long long, int>> VecStorage;
const int K = 5;

long long lazy[MAX];
VecStorage info[MAX];

VecStorage stree_merge(const VecStorage& a, const VecStorage& b) {
    VecStorage ans((int)a.size() + (int) b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin(), greater<pair<long long, int>>());
    while ((int) ans.size() > K) {
        ans.pop_back();
    }
    return ans;
}

VecStorage stree_add(const VecStorage& a, long long v) {
    VecStorage ans;
    for (auto i: a) {
        ans.push_back({i.first + v, i.second});
    }
    return ans;
}

void stree_init(int i, int lef, int rig) {
    lazy[i] = 0;
    if (lef == rig) {
        info[i].clear();
        info[i].push_back({0, lef});
        return;
    }
    int mid = (lef + rig) >> 1;
    stree_init(i<<1, lef, mid);
    stree_init(i<<1|1, mid + 1, rig);
    info[i] = stree_merge(info[i<<1], info[i<<1|1]);
}

void stree_lazy(int i) {
    lazy[i<<1] += lazy[i];
    lazy[i<<1|1] += lazy[i];
    info[i<<1] = stree_add(info[i<<1], lazy[i]);
    info[i<<1|1] = stree_add(info[i<<1|1], lazy[i]);
    lazy[i] = 0;
}

void stree_update(int i, int lef, int rig, int u, int v, int delta) {
    if (rig < u || lef > v) {
        return;
    }
    if (u <= lef && rig <= v) {
        lazy[i] += delta;
        info[i] = stree_add(info[i], delta);
        return;
    }
    int mid = (lef + rig) >> 1;
    if (lazy[i] != 0) {
        stree_lazy(i);
    }
    stree_update(i<<1, lef, mid, u, v, delta);
    stree_update(i<<1|1, mid + 1, rig, u, v, delta);
    info[i] = stree_merge(info[i<<1],info[i<<1|1]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    stree_init(1, 1, n);
    while (q--) {
        char type;
        cin >> type;
        if (type == '1') {
            int l, r, v;
            cin >> l >> r >> v;
            stree_update(1, 1, n, l, r, v);
        } else {
            int k;
            cin >> k;
            for (auto i: info[1]) {
                --k;
                cout << i.second << " ";
                if (k == 0) {
                    break;
                }
            }
            cout << "\n";
        }
    }

    cerr << "\n" << fixed << setprecision(3) << double(clock() * 1000 / CLOCKS_PER_SEC) << ".ms\n";
    return 0;
}