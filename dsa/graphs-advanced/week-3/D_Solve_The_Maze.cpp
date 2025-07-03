#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    int good_count = 0;
    
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'G') good_count++;
        }
    }

    // Surround bad people with walls
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == 'G') {
                            cout << "No" << endl;
                            return;
                        }
                        if (grid[ni][nj] == '.') grid[ni][nj] = '#';
                    }
                }
            }
        }
    }

    // BFS from (n-1, m-1)
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int vis_count = 0;

    if (grid[n - 1][m - 1] != '#') {
        q.push({n - 1, m - 1});
        visited[n - 1][m - 1] = true;
    }

    while (!q.empty()) {
        auto [curr_i, curr_j] = q.front();
        q.pop();

        if (grid[curr_i][curr_j] == 'G') vis_count++;

        for (int i = 0; i < 4; i++) {
            int new_i = curr_i + dx[i];
            int new_j = curr_j + dy[i];

            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                !visited[new_i][new_j] && grid[new_i][new_j] != '#') {
                visited[new_i][new_j] = true;
                q.push({new_i, new_j});
            }
        }
    }

    cout << ((good_count == vis_count) ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
