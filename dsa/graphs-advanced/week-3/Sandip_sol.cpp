```#pragma GCC optimize("O3,unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define int long long int
 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> shops(k);
    for (int i = 0; i < k; ++i) cin >> shops[i];

    vector<int> adj[n + 1];
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // distance and source
    // d1: first shortest distance
    // d2: second shortest distance
    vector<pair<int, int>> d1(n + 1, {INF, -1});
    vector<pair<int, int>> d2(n + 1, {INF, -1});

    queue<pair<int, int>> q; // (node, source)

    for (int s : shops)
    {
        d1[s] = {0, s};
        q.push({s, s});
    }

    while (!q.empty())
    {
        auto [u, src] = q.front();
        q.pop();
        int cur_dist = (d1[u].second == src ? d1[u].first : d2[u].first);

        for (int v : adj[u])
        {
            // Already seen this source for this node
            if (d1[v].second == src || d2[v].second == src) continue;

            int new_dist = cur_dist + 1;

            // Update distances
            if (new_dist < d1[v].first)
            {
                d2[v] = d1[v];
                d1[v] = {new_dist, src};
                q.push({v, src});
            }
            else if (new_dist < d2[v].first)
            {
                d2[v] = {new_dist, src};
                q.push({v, src});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int res;
        if (d1[i].second != i) res = d1[i].first;
        else res = (d2[i].first == INF ? -1 : d2[i].first);
        if (d1[i].first == INF && d2[i].first == INF) res = -1;
        cout << res << " ";
    }
    cout << endl;
}

signed main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}```