#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> shops(k);
    for (int i = 0; i < k; ++i) {
        cin >> shops[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int, int>> closest(n + 1, {1e9, -1});        // use 1e9 instead of LLONG_MAX
    vector<pair<int, int>> secondClosest(n + 1, {1e9, -1});

    queue<pair<int, int>> q; // {city, sourceShop}

    for (int shop : shops) {
        closest[shop] = {0, shop};
        q.push({shop, shop});
    }

    while (!q.empty()) {
        auto [city, source] = q.front();
        q.pop();

        int currentDistance = (closest[city].second == source)? closest[city].first                               : secondClosest[city].first;


        // Skip invalid starting points
        if (currentDistance >= 1e9) continue;

        for (int neighbor : adj[city]) {
            // already visited from this source
            if (closest[neighbor].second == source || secondClosest[neighbor].second == source) {
                continue;
            }

            int newDistance = currentDistance + 1;

            if (newDistance < closest[neighbor].first) {
                secondClosest[neighbor] = closest[neighbor];
                closest[neighbor] = {newDistance, source};
                q.push({neighbor, source});
            } else if (newDistance < secondClosest[neighbor].first) {
                secondClosest[neighbor] = {newDistance, source};
                q.push({neighbor, source});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int ans;
        if (closest[i].second != i) {
            ans = (closest[i].first >= 1e9 ? -1 : closest[i].first);
        } else {
            ans = (secondClosest[i].first >= 1e9 ? -1 : secondClosest[i].first);
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
