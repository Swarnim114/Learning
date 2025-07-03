#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using edge = tuple<int, int, int>;
const ll inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<edge> edges;
    vector<vector<int>> adj (n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, -w);
        adj[u].push_back(v);
    }

    vector<ll> dis(n + 1, inf);
    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (const auto& e : edges) {
            int u = get<0>(e);
            int v = get<1>(e);
            int w = get<2>(e);
            if (dis[u] != inf && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }

    vector<bool> in_cycle (n+1 , false);

    for (const auto& e : edges) {
        int u = get<0>(e);
        int v = get<1>(e);
        int w = get<2>(e);
        if (dis[u] != inf && dis[v] > dis[u] + w) {
            in_cycle[v]=true;
        }
    }
    
    vector<bool> visited(n + 1, false);
    queue<int> q ; 
    for(int i = 1 ; i < in_cycle.size() ; i++){
        if(in_cycle[i]){
            q.push(i);
            visited[i]=true;
        }
    }
   while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    if (visited[n]) {
        cout << -1 << "\n";
    } else {
        cout << -dis[n] << "\n";  
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
