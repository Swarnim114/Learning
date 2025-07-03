#include <bits/stdc++.h>
using namespace std;

void solve() {
    int Q;
    cin >> Q;
    vector<int> type(Q), A(Q), B(Q);
    for (int i = 0; i < Q; i++) {
        cin >> type[i] >> A[i];
        if (type[i] == 2) cin >> B[i];
    }
    const int MAXV = 500000 + 13;
    vector<int> mapping(MAXV);
    for (int i = 0; i < MAXV; i++) {
        mapping[i] = i;
    }
    vector<int> output;
    output.reserve(Q);
    for (int i = Q - 1; i >= 0; --i) {
        if (type[i] == 1) {
            output.push_back(mapping[A[i]]);
        } else {
            mapping[A[i]] = mapping[B[i]];
        }
    }
    reverse(output.begin(), output.end());
    for (int v : output) {
        cout << v << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
