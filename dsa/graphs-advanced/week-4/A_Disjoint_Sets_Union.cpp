#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int get_parent(int x) {
        if (x < 0 || x >= parent.size()) {
            throw out_of_range("Index out of bounds in get_parent");
        }
        if (parent[x] != x) {
            parent[x] = get_parent(parent[x]); // Path compression
        }
        return parent[x];
    }

    void merge(int x, int y) {
        if (x < 0 || x >= parent.size() || y < 0 || y >= parent.size()) {
            throw out_of_range("Index out of bounds in merge");
        }
        x = get_parent(x);
        y = get_parent(y);
        if (x == y) return;

        if (size[x] < size[y]) swap(x, y);

        parent[y] = x;
        size[x] += size[y];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1); // DSU initialized with n+1 to handle 1-based indexing

    for (int i = 0; i < m; i++) {
        string oper;
        int x, y;
        cin >> oper >> x >> y;

        if (x < 1 || x > n || y < 1 || y > n) {
            cout << "Invalid input: x or y out of bounds\n";
            continue; // Skip invalid operations
        }

        if (oper == "get") {
            int parent_x = dsu.get_parent(x);
            int parent_y = dsu.get_parent(y);

            if (parent_x == parent_y) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (oper == "union") {
            dsu.merge(x, y);
        } else {
            cout << "Invalid operation\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}