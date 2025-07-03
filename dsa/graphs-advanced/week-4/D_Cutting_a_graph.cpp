#include <bits/stdc++.h>
using namespace std;
class DSU {
private: 
    vector<int> parent ; 
    vector<int> size ; 

public: 
    DSU (int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0 ;i < n ; i++){
            parent[i]=i;
        }
    }


    int get_parent(int x){
        if(parent[x]==x)return x ; 
        return parent[x]= get_parent(parent[x]);
    }


    void merge(int x , int y){
        x = get_parent(x);
        y = get_parent(y);

        if(x == y)return ;

        if(size[x]<size[y])swap(x,y);

        parent[y]=x;
        size[x]+= size[y];
    }
};


void solve() {
    int n , m , q;
    cin >> n >> m >> q;
    for(int i = 0 ; i< m ; i++){
        int temp1 , temp2; 
        cin>> temp1 >> temp2 ; 
    }

    vector<tuple<string, int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        string type;
        int u, v;
        cin >> type >> u >> v;
        queries[i] = make_tuple(type, u, v);
    }
    DSU dsu (n+1);
    vector<string>res; 
    for(int i = q-1 ; i >=0 ; i--){
        auto [type, u, v] = queries[i];
        if(type=="ask"){
            int par_u = dsu.get_parent(u);
            int par_v = dsu.get_parent(v);

            if(par_v==par_u){
                res.push_back("YES");
            }else{
                res.push_back("NO");
            }
        }else{
            dsu.merge(u,v);
        }
    }

    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it << '\n';
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