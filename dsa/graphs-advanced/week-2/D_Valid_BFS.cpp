#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second

bool comp(int a, int b, const vector<int> &pos)
{
    return pos[a] < pos[b];
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> arr;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
        pos[num] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), [&](int a, int b)
             { return comp(a, b, pos); });
    }

    vector<int> vis(n + 1, 0);
    vis[1] = 1;

    queue<int> q;
    q.push(1);
    int idx = 0;
    while (!q.empty())
    {
        int s = q.size();
          vector<int> level;

        for (int i = 0; i < s; i++)
        {
            int curr = q.front();
            q.pop();
            vis[curr] = true;
             level.push_back(curr);

            for (int nb : adj[curr])
            {
                if (!vis[nb])
                {
                    q.push(nb);
                }
            }
        }

        for (int i = idx; i < idx + s; i++)
        {
            int num = arr[i];
            if (level[i-idx]!=num)
            {
                cout << "No" << endl;
                return;
            }
        }

        idx += s;
    }
    cout << "Yes" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; // Comment out if single test case
    while (t--)
    {
        solve();
    }

    return 0;
}