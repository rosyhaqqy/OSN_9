#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];

void dfs(int node) {
    vis[node] = true;
    cout << node << " ";

    for (int to : adj[node]) {
        if (!vis[to]) {
            dfs(to);
        } else {
            cout << "Cycle detected\n";
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }


}