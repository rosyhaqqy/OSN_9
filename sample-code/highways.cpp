#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<pair<int, int>> adj[n+1];
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    pq.push({0,s});
    bool vis[n+1];
    memset(vis, false, sizeof(vis));

    int dist, from;
    bool code = false;
    while (!pq.empty()) {
        dist = pq.top().first;
        from = pq.top().second;

        pq.pop();
        vis[from] = true;
        int sz = adj[from].size();

        if (from == e) {
            code = true;
            break;
        }

        for (int j = 0; j < sz; j++) {
            int to = adj[from][j].first;
            int weight = adj[from][j].second;

            if (!vis[to]) {
                pq.push({dist - weight, to});
            }
        }
    }

    if (pq.empty() && !code) {
        cout << "NONE\n";
    } else {
        cout << -dist << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}