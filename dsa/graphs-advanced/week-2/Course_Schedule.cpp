#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second

void solve() {
    int n,m;
    cin >> n >>m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> res ; 
    while(!q.empty()){
        int s = q.size();
        for(int i = 0 ;i < s ; i++){
            int curr = q.front();
            q.pop();
            res.pb(curr);
            for(auto nb : adj[curr]){
                indegree[nb]--;
                if(indegree[nb]==0){
                    q.push(nb);
                }
            }
        }
    }

    if(res.size()!=n){
        cout << "IMPOSSIBLE" <<" ";
        return ;
    }
    for (auto x : res) cout << x << " ";
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