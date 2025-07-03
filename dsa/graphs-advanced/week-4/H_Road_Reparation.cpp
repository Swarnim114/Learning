#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int get_parent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = get_parent(parent[x]);
    }

    void merge(int x, int y) {
        x = get_parent(x);
        y = get_parent(y);

        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);

        parent[y] = x;
        size[x] += size[y];
    }
};

bool cm (vector<int> a , vector<int> b){
    return a[2] < b[2];
}

void solve() {
    int n  , m ;
    cin >> n >> m ;

    long long  cost = 0 ; 
    DSU dsu (n+1);
    int count = 0 ; 

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    sort(edges.begin() , edges.end() , cm);
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if(dsu.get_parent(u)!=dsu.get_parent(v)){
            dsu.merge(u,v);
            cost+=w;
            count++;
            if(count==n-1)break;
        }
    }

    if(count!=n-1){
        cout << "IMPOSSIBLE";
    }else{

        cout << cost ; 
    }
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