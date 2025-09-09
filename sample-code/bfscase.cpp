#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m, s, e;
        cin >> n >> m >> s >> e;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;   // w is ignored (assumed == 1)
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS
        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[s] = 0;
        q.push(s);

        int ans = -1;
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            
            if (u == e) {               
                ans = dist[u];
                break;
            }
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (ans == -1) cout << "NONE\n";
        else cout << ans << "\n";
    }
    return 0;
}
