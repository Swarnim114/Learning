#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<pair<int,int>> key_idx;
    key_idx.reserve(n);
    for (int i = 0; i < n; i++) {
        key_idx.emplace_back(a[i] >> 2, i);
    }
    sort(key_idx.begin(), key_idx.end(),
         [](const pair<int,int> &p1, const pair<int,int> &p2) {
             if (p1.first != p2.first) return p1.first < p2.first;
             return p1.second < p2.second;
         });
    vector<int> ans(n);
    int i = 0;
    while (i < n) {
        int j = i;
        // find range [i, j) with same key
        while (j < n && key_idx[j].first == key_idx[i].first) j++;
        int len = j - i;
        vector<int> vals;
        vals.reserve(len);
        for (int k = i; k < j; k++) {
            vals.push_back(a[key_idx[k].second]);
        }
        sort(vals.begin(), vals.end());
        for (int k = i; k < j; k++) {
            ans[key_idx[k].second] = vals[k - i];
        }
        i = j;
    }
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
