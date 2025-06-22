#include <bits/stdc++.h>
using namespace std;
using ll = long long ; 
using T = tuple <ll , ll , bool  >;
using Pair = pair<ll , ll>;

void solve() {
    int n , m ;
    cin >> n >> m ;
    vector<vector<Pair>> adj(n + 1);
    vector<ll> dis1 (n+1 , 1e18);
    vector<ll> dis2 (n+1 , 1e18);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Pair(v, w));
    }

    dis1[1] = dis2[1]=0;

    priority_queue <T , vector<T> , greater<T>> q ; 
    q.emplace(0,1,false);
    while(!q.empty()){
        T curr = q.top();
        q.pop();

        ll currNode = get<1>(curr);
        ll currDis = get<0>(curr);
        bool coupon_used = get<2>(curr);

        if(coupon_used){
            if(currDis > dis2[currNode])continue;
        }else{
            if(currDis > dis1[currNode])continue;

        }
        for(auto nb : adj[currNode]){
            ll nbNode = nb.first;
            ll nbW = nb.second ; 

            if(coupon_used){
                if(currDis + nbW < dis2[nbNode]){
                    dis2[nbNode] = currDis + nbW;
                    q.emplace(dis2[nbNode] , nbNode , true);
                }
            }else{
                if(currDis + nbW < dis1[nbNode]){
                    dis1[nbNode] = currDis + nbW;
                    q.emplace(dis1[nbNode] , nbNode , false);
                }

                if(currDis + nbW/2 < dis2[nbNode]){
                    dis2[nbNode] = currDis + nbW/2;
                    q.emplace(dis2[nbNode] , nbNode , true);
                }
            }
        }

        
    }

    ll res = min (dis1[n] , dis2[n]);
    cout << res ;
    cout << "\n";
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