#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e18;

void solve() {
    int n, m;
    ll X;
    cin >> n >> m >> X;

    vector<vector<int>> adj(n), rev(n);
    for (int i = 0; i < m; ++i) {
        int nb, v;
        cin >> nb >> v;
        --nb; --v;
        adj[nb].push_back(v);
        rev[v].push_back(nb);
    }

    vector<array<ll, 2>> dist(n, {INF, INF});
    using T = tuple<ll, int, int>; // (dist, node, orientation) ori = 0 rev = 1
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0][0] = 0;
    pq.emplace(0, 0, 0); // Start at node 0 original orientation

    while (!pq.empty()) {
        auto [dis, node, ori] = pq.top();
        pq.pop();
        if (dis != dist[node][ori]) continue;

        if (ori == 0) {
            for (int nb : adj[node]) {
                if (dis + 1 < dist[nb][0]) {
                    dist[nb][0] = dis + 1;
                    pq.emplace(dis + 1, nb, 0);
                }
            }
            for (int nb : rev[node]) {
                if (dis + X + 1 < dist[nb][1]) {
                    dist[nb][1] = dis + X + 1;
                    pq.emplace(dis + X + 1, nb, 1);
                }
            }
        } else {
            for (int nb : rev[node]) {
                if (dis + 1 < dist[nb][1]) {
                    dist[nb][1] = dis + 1;
                    pq.emplace(dis + 1, nb, 1);
                }
            }
            for (int nb : adj[node]) {
                if (dis + X + 1 < dist[nb][0]) {
                    dist[nb][0] = dis + X + 1;
                    pq.emplace(dis + X + 1, nb, 0);
                }
            }
        }
    }

    cout << min(dist[n - 1][0], dist[n - 1][1]) << '\n';
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
