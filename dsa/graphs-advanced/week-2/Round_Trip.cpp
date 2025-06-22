#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second

vector<vector<int>> adj; 
vector<bool> vis ; 
vector<int> par ; 
int start = -1, endd = -1;


bool dfs(int node , int parent){
    vis[node]=true;
    par[node]=parent;

    
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue; // Don't go back to the parent
        if (vis[neighbor]) {
            // Found a cycle
            start = neighbor;
            endd = node;
            return true;
        }
        if (dfs(neighbor, node)) return true;
    }

    return false;
}
void solve() {
    // Input
    int n ,m;
    cin >> n >> m; // n nodes // m edges 
    adj.assign(n , vector<int>());
    for(int i = 0 ; i < m ; i++){
        int u , v ; 
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    

    vis.assign(n,false);
    par.assign(n , -1);

    for(int i = 0 ; i < n ; i++){
        if(!vis[i] && dfs(i , par[i])){
            return ;
        }
    }

   
    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = endd; v != start; v = par[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int x : cycle) cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    solve();

    return 0;
}