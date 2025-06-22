#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
int dx [] = {1,-1,1,-1,2,-2,2,-2};
int dy [] = {2,2,-2,-2,1,1,-1,-1};

void solve() {
    string start , end ; 
    cin >> start >> end ; 

    int col1 = start[0]-'a' +1 ;
    int row1 = 8-(start[1]-'1' );

    int col2 = end[0]-'a' +1 ;
    int row2 = 8 - (end[1]-'1'); 

    pair <int , int > st (row1,col1);
    pair <int , int > ed (row2,col2);

    // cout << st.F << " " << st.S << " " << ed.F << " " << ed.S ;
    // cout << endl ;  

    //bfs 
    queue <pair<int,int>> q ; 
    vector<vector<bool>> vis (8, (vector<bool> (8 ,false)));
    q.push(st);
    int count = 0 ; 
    while(!q.empty()){
        int s = q.size();
        for(int i = 0 ; i < s; i ++){
            pair <int , int >curr = q.front(); 
            q.pop();
            if(curr.F == ed.F && curr.S==ed.S){
                cout << count << endl ;
                return ; 
            }

            for(int a = 0 ; a < 8 ; a++){
                int newx = curr.F + dx[a];
                int newy = curr.S + dy[a];

                if(newx>=1 && newy>=1 && newx<=8 && newy<=8){
                    if(vis[newx-1][newy-1]==false){
                        q.push(pair <int , int > (newx , newy));
                        vis[newx-1][newy-1]=true;
                    }
                }
            }

        }
        count ++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t; // Comment out if single test case
    while(t--) {
        solve();
    }

    return 0;
}