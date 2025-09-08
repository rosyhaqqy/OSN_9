#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int node) {
    vis[node] = true;
    cout << node << " "; 

    for (int to : adj[node]) {
        if (!vis[to]) {
            dfs(to); 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    memset(vis, false, sizeof(vis));

    dfs(1);

    return 0;
}
