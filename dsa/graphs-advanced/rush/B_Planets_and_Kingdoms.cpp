#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1), gr(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    vector<bool> vis(n+1, false);
    vector<int> order;
    order.reserve(n);
    function<void(int)> dfs1 = [&](int u) {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v])
                dfs1(v);
        order.push_back(u);
    };
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);
    fill(vis.begin(), vis.end(), false);
    vector<int> comp(n+1);
    int cid = 0;
    function<void(int)> dfs2 = [&](int u) {
        vis[u] = true;
        comp[u] = cid;
        for (int v : gr[u])
            if (!vis[v])
                dfs2(v);
    };
    for (int i = n-1; i >= 0; i--) {
        int u = order[i];
        if (!vis[u]) {
            cid++;
            dfs2(u);
        }
    }
    cout << cid << "\n";
    for (int i = 1; i <= n; i++) {
        cout << comp[i] << (i==n?'\n':' ');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t; // Comment out if single test case
    while (t--) {
        solve();
    }

    return 0;
}
