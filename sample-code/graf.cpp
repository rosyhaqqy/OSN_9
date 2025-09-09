#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 5;
    vector<vector<int>> adj(n + 1, vector<int>(n+1, 0));

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}