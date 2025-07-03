#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int get_parent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = get_parent(parent[x]);
    }

    void merge(int x, int y) {
        x = get_parent(x);
        y = get_parent(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }

    int get_size(int x) {
        return sz[get_parent(x)];
    }
};

void solve() {
    int N;
    cin >> N;

    // We may see up to 2*N distinct names in one test
    DSU dsu(2 * N );
    unordered_map<string, int> id;
    id.reserve(2 * N);
    int next_id = 0;

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        if (!id.count(a)) id[a] = next_id++;
        if (!id.count(b)) id[b] = next_id++;

        int ia = id[a];
        int ib = id[b];
        dsu.merge(ia, ib);

        cout << dsu.get_size(ia) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
