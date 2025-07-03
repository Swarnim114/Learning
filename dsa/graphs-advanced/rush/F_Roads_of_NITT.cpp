#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    vector<long long> sz;
    long long reachable;
    DSU(int n): p(n+1), sz(n+1,1), reachable(0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x]==x?x:p[x]=find(p[x]);
    }
    void unite(int u,int v){
        u=find(u); v=find(v);
        if(u==v) return;
        // merge smaller into larger
        if(sz[u]<sz[v]) swap(u,v);
        // subtract old contributions
        reachable -= sz[u]*(sz[u]-1LL)/2;
        reachable -= sz[v]*(sz[v]-1LL)/2;
        p[v]=u;
        sz[u]+=sz[v];
        // add new
        reachable += sz[u]*(sz[u]-1LL)/2;
    }
};

void solve(){
    int N;
    cin>>N;
    vector<pair<int,int>> edges(N);
    for(int i=1;i<N;i++){
        cin>>edges[i].first>>edges[i].second;
    }
    int Q;
    cin>>Q;
    vector<char> qt(Q);
    vector<int> qx(Q);
    for(int i=0;i<Q;i++){
        cin>>qt[i];
        if(qt[i]=='R') cin>>qx[i];
    }
    vector<bool> removed(N,false);
    for(int i=0;i<Q;i++){
        if(qt[i]=='R'){
            removed[qx[i]] = true;
        }
    }
    DSU dsu(N);
    // initially add all edges not removed
    for(int i=1;i<N;i++){
        if(!removed[i]){
            dsu.unite(edges[i].first, edges[i].second);
        }
    }
    long long totalPairs = N*(N-1LL)/2;
    vector<long long> ans;
    ans.reserve(Q);
    for(int i=Q-1;i>=0;i--){
        if(qt[i]=='Q'){
            ans.push_back(totalPairs - dsu.reachable);
        } else {
            int ei = qx[i];
            dsu.unite(edges[ei].first, edges[ei].second);
        }
    }
    reverse(ans.begin(), ans.end());
    int ai = 0;
    for(int i=0;i<Q;i++){
        if(qt[i]=='Q'){
            cout<<ans[ai++]<<"\n";
        }
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
