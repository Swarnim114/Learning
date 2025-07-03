#include <bits/stdc++.h>
using namespace std;
void solve() {
    string line;
    
    // Read the variables
    getline(cin, line);
    istringstream iss(line);
    vector<char> nodes;
    char node;
    while (iss >> node) {
        nodes.push_back(node);
    }
    
    // Read the constraints
    getline(cin, line);
    iss.clear();
    iss.str(line);
    string constraint;
    vector<pair<char, char>> edges;
    while (iss >> constraint) {
        if (constraint.size() == 3 && constraint[1] == '<') {
            char from = constraint[0];
            char to = constraint[2];
            edges.push_back({from, to});
        }
    }
    
    // Print the nodes and edges (just for verification)
    cout << "Nodes: ";
    for (char n : nodes) {
        cout << n << " ";
    }
    cout << endl;
    
    cout << "Edges: ";
    for (auto [from, to] : edges) {
        cout << from << "->" << to << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t; // Read number of test cases
    cin.ignore(); // Ignore the newline after t
    
    string blank;
    getline(cin, blank); // Read blank line after t
    
    for (int i = 0; i < t; i++) {
        if (i > 0) {
            // Read blank line between test cases
            getline(cin, blank);
        }
        solve();
        if (i < t-1) cout << endl;
    }

    return 0;
}