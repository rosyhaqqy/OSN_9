#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[1001];
vector<int> dist(1001, INT_MAX);
bool vis[1001];
void djikstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // {distance, node}
    dist[start] = 0;

    while(!pq.empty()) {
        int currNode = pq.top().second;
        int currDist = pq.top().first;

        pq.pop();

        if (vis[currNode]) continue;

        vis[currNode] = true;
        cout << "\n====\n" ;
        // cout << currNode << " ";

        if (currNode == end) {
            cout << "\nReached destination\n";
            cout << "Shortest path: " << currDist << "\n";
            return;
        }

        int sz = adj[currNode].size();
        for (int i = 0; i < sz; i++) {
            int to = adj[currNode][i].first;
            int weight = adj[currNode][i].second;

            if (currDist + weight < dist[to]) {
                dist[to] = currDist + weight;
                cout << "Push " << to << "\n";
                pq.push({dist[to], to});
            }
        }
    }
}

int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    djikstra(s, e);

    cout << "\n";

    for (int i = 1; i <= n; i++) {
        cout << i << " : " << dist[i] << "\n";
    }

}