#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    // dp[i][j] = maximum pages using items from i..n-1 with budget j
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= x; j++) {

            int nottake = dp[i + 1][j];

            int take = INT_MIN;
            if (j - prices[i] >= 0) {
                take = pages[i] + dp[i + 1][j - prices[i]];
            }

            dp[i][j] = max(take, nottake);
        }
    }

    cout << dp[0][x] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
