#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
void solve() {
    int n ,m;
    cin >> n >>m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    vector<long long> dp(n + 1, 0);
    dp[1] = 1; 
    
    for (int u : topo) {
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }
    
    cout << dp[n];


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