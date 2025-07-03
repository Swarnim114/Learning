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
        if (parent[x] == x) return x;
        return parent[x] = get_parent(parent[x]);
    }

    void merge(int x, int y) {
        x = get_parent(x);
        y = get_parent(y);

        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);

        parent[y] = x;
        size[x] += size[y];
    }
};
void solve() {
    int n;
    cin >> n;


    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t; // Comment out if single test case
    while(t--) {
        solve();
    }

    return 0;
}