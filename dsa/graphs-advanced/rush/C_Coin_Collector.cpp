#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numRooms, numTunnels;
    cin >> numRooms >> numTunnels;
    vector<long long> coins(numRooms+1);
    for (int i = 1; i <= numRooms; i++) cin >> coins[i];
    vector<vector<int>> graph(numRooms+1), revGraph(numRooms+1);
    for (int i = 0; i < numTunnels; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
    }
    vector<bool> visited(numRooms+1,false);
    vector<int> order;
    order.reserve(numRooms);
    function<void(int)> dfs1 = [&](int u) {
        visited[u] = true;
        for (int v : graph[u])
            if (!visited[v])
                dfs1(v);
        order.push_back(u);
    };
    for (int i = 1; i <= numRooms; i++)
        if (!visited[i])
            dfs1(i);
    vector<int> component(numRooms+1,0);
    int compCount = 0;
    vector<long long> compSum(numRooms+1,0);
    function<void(int)> dfs2 = [&](int u) {
        for (int v : revGraph[u])
            if (!component[v]) {
                component[v] = compCount;
                compSum[compCount] += coins[v];
                dfs2(v);
            }
    };
    for (int i = numRooms-1; i >= 0; i--) {
        int u = order[i];
        if (!component[u]) {
            compCount++;
            component[u] = compCount;
            compSum[compCount] += coins[u];
            dfs2(u);
        }
    }
    vector<vector<int>> dag(compCount+1);
    vector<int> indeg(compCount+1,0);
    for (int u = 1; u <= numRooms; u++) {
        for (int v : graph[u]) {
            int cu = component[u], cv = component[v];
            if (cu != cv) {
                dag[cu].push_back(cv);
            }
        }
    }
    for (int u = 1; u <= compCount; u++) {
        sort(dag[u].begin(), dag[u].end());
        dag[u].erase(unique(dag[u].begin(), dag[u].end()), dag[u].end());
        for (int v : dag[u]) indeg[v]++;
    }
    queue<int> q;
    vector<long long> dp(compCount+1,0);
    for (int u = 1; u <= compCount; u++) {
        dp[u] = compSum[u];
        if (indeg[u] == 0) q.push(u);
    }
    long long answer = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        answer = max(answer, dp[u]);
        for (int v : dag[u]) {
            dp[v] = max(dp[v], dp[u] + compSum[v]);
            if (--indeg[v] == 0) q.push(v);
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) solve();
    return 0;
}
