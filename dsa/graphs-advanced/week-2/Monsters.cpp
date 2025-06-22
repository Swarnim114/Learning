#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

bool valid(int i, int j, int n, int m) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    
    int startX = -1, startY = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }

    queue<pair<int,int>> q;
    vector<vector<int>> monster(n, vector<int>(m, INT_MAX));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'M') {
                q.push({i, j});
                monster[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.F;
        int y = curr.S;

        for(int d = 0; d < 4; d++) {
            int newx = x + dx[d];
            int newy = y + dy[d];

            if(valid(newx, newy, n, m) && grid[newx][newy] != '#' && 
               monster[newx][newy] > monster[x][y] + 1) {
                monster[newx][newy] = monster[x][y] + 1;
                q.push({newx, newy});
            }
        }
    }

    vector<vector<int>> playerTime(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<char>> parentDir(n, vector<char>(m, ' '));
    
    q.push({startX, startY});
    playerTime[startX][startY] = 0;

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.F;
        int y = curr.S;

        // Check if we reached boundary
        if(x == 0 || x == n-1 || y == 0 || y == m-1) {
            cout << "YES" << endl;
            
            // Reconstruct path
            string path = "";
            int curX = x, curY = y;
            
            while(parent[curX][curY].F != -1) {
                path += parentDir[curX][curY];
                auto p = parent[curX][curY];
                curX = p.F;
                curY = p.S;
            }
            
            reverse(path.begin(), path.end());
            cout << path.length() << endl;
            cout << path << endl;
            return;
        }

        for(int d = 0; d < 4; d++) {
            int newx = x + dx[d];
            int newy = y + dy[d];

            if(valid(newx, newy, n, m) && grid[newx][newy] != '#' && 
               playerTime[newx][newy] == INT_MAX && 
               playerTime[x][y] + 1 < monster[newx][newy]) {
                
                playerTime[newx][newy] = playerTime[x][y] + 1;
                parent[newx][newy] = {x, y};
                parentDir[newx][newy] = dir[d];
                q.push({newx, newy});
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}