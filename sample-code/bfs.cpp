#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool vis[n+1];
    memset(vis, false, sizeof(vis));

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int from = q.front();
        q.pop();
        cout << from << " ";

        int sz = adj[from].size();
        for (int j = 0; j < sz; j++) {
            int to = adj[from][j];
            if (!vis[to]) {
                vis[to] = true;
                q.push(to);
            }
        }
    }
    cout << "\n";
}