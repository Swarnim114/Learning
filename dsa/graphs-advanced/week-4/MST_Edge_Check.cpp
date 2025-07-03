#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Disjoint Set Union (Union-Find) class

bool compareByWeight(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}
class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    // Each edge: u, v, w, index
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    // Sort edges by weight
    // struct EdgeCmp {
    //     bool operator()( vector<int> A,  vector<int> B)  {
    //         return A[2] < B[2];
    //     }
    // };
    sort(edges.begin(), edges.end(), compareByWeight);

    DSU dsu(n + 1);
    vector<string> answer(m);

    int i = 0;
    while (i < m) {
        int j = i;
        while (j < m && edges[j][2] == edges[i][2]) j++;

        for (int k = i; k < j; k++) {
            int u = edges[k][0];
            int v = edges[k][1];
            int idx = edges[k][3];
            if (dsu.same(u, v))
                answer[idx] = "NO";
            else
                answer[idx] = "YES";
        }
        for (int k = i; k < j; k++) {
            int u = edges[k][0];
            int v = edges[k][1];
            dsu.unite(u, v);
        }
        i = j;
    }

    // Print answers in original order
    for (int x = 0; x < m; x++) {
        cout << answer[x] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
