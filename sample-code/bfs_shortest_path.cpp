#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];

void bfs(int start, int end) {
    queue <pair<int, int>> q;
    q.push({start, 1});
    
    while(!q.empty()) {
        int curr = q.front().first;
        int counter = q.front().second;
        q.pop();
        vis[curr] = true;
        cout << curr << " ";

        if (curr == end) {
            cout << "\nPath Found\n";
            cout << "Shortest path: " << counter << "\n";
            return;
        }

        int sz = adj[curr].size();
        for (int i = 0; i < sz; i++) {
            int to = adj[curr][i];
            if (!vis[to]) {
                q.push({to, counter + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, e;
    cin >> n >> m >> s >> e;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(s, e);

}