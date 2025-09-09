#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];

void dfs(int node) {
    // vis[node] = true;

    stack<int> s;
    s.push(node);

    while(!s.empty()) {
        int curr = s.top();
        s.pop();
        vis[curr] = true;
        cout << curr << " ";

        int sz = adj[curr].size();

        for (int i = 0; i < sz; i++) {
            int to = adj[curr][i];
            if (!vis[to]) {
                s.push(to);
            } else {
                cout << "Cycle detected\n";
                exit(0);
            }
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