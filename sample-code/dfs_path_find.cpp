#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
bool isFound;
void find_withDFS(int node, int end) {
    vis[node] = true;
    cout << node << " ";

    if (node == end) {
        cout << "\nPath Found\n";
        isFound = true;
        return;
    }

    int sz = adj[node].size();

    for (int i = 0; i < sz; i++) {
        int to = adj[node][i];
        if (!vis[to]) {
            find_withDFS(to, end);
        }
    }
}

void find_withDFSStack(int node, int end) {
    stack<int> s;
    s.push(node);

    while(!s.empty()) {
        int curr = s.top();
        s.pop();
        vis[curr] = true;
        cout << curr << " ";

        if (curr == end) {
            cout << "\nPath Found\n";
            isFound = true;
            return;
        }

        
        int sz = adj[node].size();

        for (int i = 0; i < sz; i++) {
            int to = adj[node][i];
            if (!vis[to]) {
                s.push(to);
            }
        }

    }

    
}

int main() {
    // Maze represented as a graph
    // is there a path from S to E?
    int n, m, s, e;
    cin >> n >> m >> s >> e;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_withDFSStack(s, e);
    if (!isFound) cout << "\nNo Path Found\n";
}