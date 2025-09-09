#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];

void countGraph(int node) {
    vis[node] = true;
    cout << node << " ";
    int sz = adj[node].size();
    for (int i = 0; i < sz; i++) {
        int to = adj[node][i];
        if (!vis[to]) {
            countGraph(to);
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
        adj[v].push_back(u);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]){
            count++;
            countGraph(i);
        }
    }

    cout << "Number of graphs: " << count << "\n";

}