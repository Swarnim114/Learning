#include <bits/stdc++.h>
using namespace std;
using ll = long long  ; 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], (ll)w); 
    }

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    ll res = 0 ; 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
                if (dist[i][j] == LLONG_MAX) {
                    continue;
                } else {
                    res+=dist[i][j];
                }
            }
        }
    }

    cout << res;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t; // Uncomment if multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}