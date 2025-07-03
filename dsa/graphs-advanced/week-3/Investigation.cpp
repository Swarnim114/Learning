#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pair = pair<ll, ll>;
const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<Pair>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Pair(v, w));
    }

    vector<ll> dist(n + 1, 1e18);22
    vector<ll> path(n + 1, 0);
    vector<ll> minNode(n + 1, 1e18);
    vector<ll> maxNode(n + 1, 0);

    dist[1] = 0;
    path[1] = 1;
    minNode[1] = 0;
    maxNode[1] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push(Pair(0, 1)); // (distance, node)

    while (!pq.empty()) {
        Pair curr = pq.top();
        pq.pop();

        ll currDist = curr.first;
        ll node = curr.second;

        if (currDist > dist[node]) continue;

        for (auto& edge : adj[node]) {
            ll neighbor = edge.first;
            ll weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                path[neighbor] = path[node];
                minNode[neighbor] = minNode[node] + 1;
                maxNode[neighbor] = maxNode[node] + 1;
                pq.push(Pair(dist[neighbor], neighbor));
            } else if (dist[node] + weight == dist[neighbor]) {
                path[neighbor] = (path[neighbor] + path[node]) % MOD;
                minNode[neighbor] = min(minNode[neighbor], minNode[node] + 1);
                maxNode[neighbor] = max(maxNode[neighbor], maxNode[node] + 1);
            }
        }
    }

    cout << dist[n] << " " << path[n] << " " << minNode[n] << " " << maxNode[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
