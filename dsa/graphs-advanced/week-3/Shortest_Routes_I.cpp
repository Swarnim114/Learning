#include <bits/stdc++.h>
using namespace std;

using Pair = pair<long long , long long >; 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<Pair>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Pair(v, w));
    }

    vector<long long > dist(n + 1, 1e18); 
    dist[1] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push(Pair(0, 1)); // (distance, node)

    while (!pq.empty()) {
        Pair curr = pq.top();
        pq.pop();

        long long currDist = curr.first;
        long long node = curr.second;

        if (currDist > dist[node]) continue;

        for (int i = 0; i < adj[node].size(); i++) {
            long long  neighbor = adj[node][i].first;
            long long  weight = adj[node][i].second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push(Pair(dist[neighbor], neighbor));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
