#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[100001];
bool vis[100001];
bool isFound = false;
int dist;

void djikstra(int start, int end) {
	priority_queue<pair<int,int>> pq;
	pq.push({0, start});
	dist = 0;
	
	while(!pq.empty()) {
		int currDist = pq.top().first;
		int currNode = pq.top().second;
		
		cout << currNode << " " << currDist << endl;
 		
		pq.pop();
		if (vis[currNode]) continue;
		
		vis[currNode] = true;
		
		if (currNode == end){
			isFound = 1;
			return;
		}
		
		int sz = adj[currNode].size();
		for (int i = 0; i < sz; i++) {
			int nextNode = adj[currNode][i].first;
			int weight = adj[currNode][i].second;
			
			cout << currDist - weight << " " << dist << "\n";
			if (!vis[nextNode]) {
			   dist = dist - weight;
				pq.push({dist, nextNode});
			}
		}
	}
	
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, s, e;
		scanf("%d%d%d%d", &n, &m, &s, &e);
		
		for (int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		memset(vis, false, sizeof(vis));
		dist = 0;
		djikstra(s,e);
		
		if (isFound) {
			printf("%d\n", -1*dist);
		} else {
			printf("NONE\n");
		}
	}

}
