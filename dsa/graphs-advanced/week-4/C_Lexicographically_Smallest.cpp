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
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int m;
    cin >> m;

    // DSU over positions [0..n-1]
    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // union the two indices
        dsu.merge(u, v);
    }

    // Group all indices by their root parent
    unordered_map<int, vector<int>> comp;
    comp.reserve(n);
    for (int i = 0; i < n; i++) {
        int r = dsu.get_parent(i);
        comp[r].push_back(i);
    }

    // Build the result string
    string res = s;
    for (auto pair : comp) {
        auto indices = pair.second;

        vector<char> chars;

        for (int idx : indices) {
            chars.push_back(s[idx]);
        }
        
        sort(indices.begin(), indices.end());
        sort(chars.begin(), chars.end());
        for (int k = 0; k < (int)indices.size(); k++) {
            res[indices[k]] = chars[k];
        }
    }

    cout << res << "\n";
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
