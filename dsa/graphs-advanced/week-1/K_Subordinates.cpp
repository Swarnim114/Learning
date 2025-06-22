#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second

void dfs(int node,  vector<vector<int>>& adj, vector<int>& res) {
    int cnt = 0;
    for (int child : adj[node]) {
        dfs(child, adj, res);
        cnt += 1 + res[child];
    }
    res[node] = cnt;
}

void solve() {
    // Input
    int n;
    cin >> n;
    vector<int> arr ;
    arr.push_back(-1);
    for(int i = 0 ; i < n-1 ; i++){
        int num;
        cin>>num; 
        arr.push_back(num);
    }

    
    vector<vector<int>> adj(n + 1);
    
    for(int i = 2 ; i <=n ; i++){
        int parent = arr[i-1];
        adj[parent].push_back(i);
    }

    
    // Print adjacency list
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int v : adj[i]) cout << v << " ";
    //     cout << endl;
    // }

    vector<int> res (n+1 ,0);

    dfs(1,adj,res);

    for(int i = 1 ; i<=n ; i++){
        cout << res[i] <<" ";
    }
    cout << endl ; 
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