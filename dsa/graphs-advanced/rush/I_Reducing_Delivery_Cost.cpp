#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n+1);
    struct Edge{int u,v,w;};
    vector<Edge> edges;
    edges.reserve(m);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
        edges.push_back({u,v,w});
    }
    vector<pair<int,int>> routes(k);
    for(int i=0;i<k;i++){
        cin >> routes[i].first >> routes[i].second;
    }
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    vector<ll> d(n+1);
    for(int s=1;s<=n;s++){
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        pq.emplace(0,s);
        while(!pq.empty()){
            auto [du,u] = pq.top(); pq.pop();
            if(du != d[u]) continue;
            for(auto &pr: adj[u]){
                int v = pr.first, w = pr.second;
                if(du + w < d[v]){
                    d[v] = du + w;
                    pq.emplace(d[v], v);
                }
            }
        }
        // copy
        for(int v=1;v<=n;v++) dist[s][v] = d[v];
    }
    ll base = 0;
    for(auto &rt: routes){
        base += dist[rt.first][rt.second];
    }
    ll answer = base;
    for(auto &e: edges){
        int u = e.u, v = e.v;
        ll sum = 0;
        for(auto &rt: routes){
            int a = rt.first, b = rt.second;
            ll alt = min(dist[a][u] + dist[v][b],
                         dist[a][v] + dist[u][b]);
            sum += min(dist[a][b], alt);
        }
        answer = min(answer, sum);
    }
    cout << answer << "\n";
    return 0;
}
