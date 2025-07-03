#include <bits/stdc++.h>
using namespace std;

void solve() {
    int testCount;
    cin >> testCount;
    for (int tc = 1; tc <= testCount; tc++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> disc(n + 1, 0), low(n + 1, 0);
        vector<bool> seen(n + 1, false);
        int timer = 0;
        vector<pair<int,int>> bridges;
        function<void(int,int)> dfs = [&](int u, int parent) {
            seen[u] = true;
            disc[u] = low[u] = ++timer;
            for (int v : adj[u]) {
                if (v == parent) continue;
                if (!seen[v]) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > disc[u]) {
                        int a = u, b = v;
                        if (a > b) swap(a, b);
                        bridges.emplace_back(a, b);
                    }
                } else {
                    low[u] = min(low[u], disc[v]);
                }
            }
        };
        dfs(1, 0);
        sort(bridges.begin(), bridges.end());
        cout << "Caso #" << tc << "\n";
        if (bridges.empty()) {
            cout << "Sin bloqueos\n";
        } else {
            cout << bridges.size() << "\n";
            for (auto &e : bridges) {
                cout << e.first << " " << e.second << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
