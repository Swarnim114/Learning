#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum) {
    int n;
    cin >> n;
    
    // Read beverage names
    vector<string> beverages(n);
    for (int i = 0; i < n; i++) {
        cin >> beverages[i];
    }
    
    // Read relations between beverages
    int m;
    cin >> m;
    
    vector<pair<string, string>> relations;
    for (int i = 0; i < m; i++) {
        string b1, b2;
        cin >> b1 >> b2;
        relations.push_back({b1, b2});
    }
    
    // Just print the input for verification
    cout << "Case #" << caseNum << ": Beverages read:" << endl;
    cout << "Total beverages: " << n << endl;
    for (const auto& beverage : beverages) {
        cout << "- " << beverage << endl;
    }
    
    cout << "Total relations: " << m << endl;
    for (const auto& [b1, b2] : relations) {
        cout << "- " << b1 << " comes before " << b2 << endl;
    }
    
    // Actual solution would go here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNum = 1;
    int n;
    
    while (cin >> n) {
        solve(caseNum++);
        string blank;
        getline(cin, blank); // Read the blank line after each test case
    }

    return 0;
}