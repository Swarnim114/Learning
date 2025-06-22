#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second

pair<int, int> dfs(int node, int parent, const vector<vector<int>>& adj) {
    pair<int, int> res = {0, node}; 
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            pair<int, int> sub = dfs(neighbor, node, adj);
            sub.first++;
            if (sub.first > res.first) res = sub;
        }
    }
    return res;
}

void solve() {
    // Input
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int far_node = dfs(1, -1, adj).second;
    int diameter = dfs(far_node, -1, adj).first;
    cout << diameter << endl;
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