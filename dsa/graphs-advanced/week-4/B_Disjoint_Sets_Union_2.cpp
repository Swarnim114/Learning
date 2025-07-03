#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class DSU {
private:
    vector<int> parent; 
    vector<int> size;   
    vector<int> mx;
    vector<int> mn; 
    
public: 
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        mx.resize(n);
        mn.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            mx[i] = mn[i] = i; 
        }
    }   
    
    int get_parent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = get_parent(parent[x]); // path compression
    }

    int get_min(int x) {
        return mn[get_parent(x)];
    }

    int get_max(int x) {
        return mx[get_parent(x)];
    }

    int get_size(int x) {
        return size[get_parent(x)];
    }

    void merge(int x, int y) {
        x = get_parent(x);
        y = get_parent(y);
        if (x == y) return;

        if (size[x] < size[y]) swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        mn[x] = min(mn[x], mn[y]);
        mx[x] = max(mx[x], mx[y]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1); // 1-based indexing

    for (int i = 0; i < m; i++) {
        string oper; 
        cin >> oper;

        if (oper == "get") {
            int x;
            cin >> x;
            cout << dsu.get_min(x) << " " << dsu.get_max(x) << " " << dsu.get_size(x) << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            dsu.merge(x, y);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
