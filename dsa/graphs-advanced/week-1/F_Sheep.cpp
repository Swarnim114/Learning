#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

pair<int, int> dfs(int i, int j, vector<vector<char>>& grid) {
    pair<int, int> res = {0, 0};
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return res;
    if (grid[i][j] == '#') return res;

    char ch = grid[i][j];
    grid[i][j] = '#';

    if (ch == 'k') res.F++;
    if (ch == 'v') res.S++;

    for (int a = 0; a < 4; a++) {
        int newX = i + dx[a];
        int newY = j + dy[a];

        pair<int, int> temp = dfs(newX, newY, grid);
        res.F += temp.F;
        res.S += temp.S;
    }

    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    pair<int, int> count = {0, 0};

    for (int i = 0; i < n; i++) {
        if (grid[i][0] != '#') {
            pair<int, int> temp = dfs(i, 0, grid);
            count.F += temp.F;
            count.S += temp.S;
        }

        if (grid[i][m-1] != '#') {
            pair<int, int> temp = dfs(i, m-1, grid);
            count.F += temp.F;
            count.S += temp.S;
        }

    }

  

    for (int j = 0; j < m; j++) {
        if (grid[0][j] != '#') {
            pair<int, int> temp = dfs(0, j, grid);
            count.F += temp.F;
            count.S += temp.S;
        }
        if (grid[n-1][j] != '#') {
            pair<int, int> temp = dfs(n-1, j, grid);
            count.F += temp.F;
            count.S += temp.S;
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '#') {
                pair<int, int> temp = dfs(i, j, grid);
                if (temp.F > temp.S) {
                    count.F += temp.F;
                } else {
                    count.S += temp.S;
                }
            }
        }
    }

    cout << count.F << " " << count.S << endl;
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
