#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 5;
    vector<pair <int, int>> adjList[n+1];
    vector<pair<pair<int, int>, int>> edges;

    edges.push_back({{1,2},10});

    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto p : adjList[i]) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "\n";
    }
}