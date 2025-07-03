#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> disc(n+1, 0), low(n+1, 0), parent(n+1, 0), sz(n+1, 0);
    vector<pair<int,int>> bridges;
    int timer = 0;
    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = ++timer;
        sz[u] = 1;
        for (int v : adj[u]) {
            if (!disc[v]) {
                parent[v] = u;
                dfs(v);
                sz[u] += sz[v];
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.emplace_back(u, v);
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    };
    dfs(1);
    long long total = 1LL * n * (n - 1) / 2;
    long long maxCut = 0;
    for (auto &e : bridges) {
        int u = e.first, v = e.second;
        long long s = sz[v];
        long long t = n - s;
        maxCut = max(maxCut, s * t);
    }
    long long result = total - maxCut;
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
