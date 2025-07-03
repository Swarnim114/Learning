#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> indegree(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }
    vector<int> parent(n + 1, -1);
    queue<int> q;
    vector<int> topo;

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }
    vector<int> dist(n + 1, -1);
    vector<int> path(n + 1, -1);
    dist[1] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (dist[u] != -1 && dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
                path[v] = u;
            }
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << dist[n] << "\n";
    vector<int> res;
    int v = n;
    while (v != -1) {
        res.push_back(v);
        v = path[v];
    }
    reverse(res.begin(), res.end());
    for (int v : res) cout << v << " ";
    cout << "\n";
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
