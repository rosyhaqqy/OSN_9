#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;
    vector<pair<long, pair<long, long>>> edgeList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;
        adjList.clear();
        edgeList.clear();

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({});
        }
    }

    void add_edge(long vertex1, long vertex2, long weight)
    {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));

        edgeList.push_back(make_pair(weight, make_pair(vertex1, vertex2)));
        edgeCount++;
    }

    // DFS
    void dfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!st.empty())
        {
            long temp = st.top();
            st.pop();

            if (!visited[temp])
            {
                result.push_back(temp);
                visited[temp] = true;
            }

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                    st.push(vertex.first);
            }
        }
    }

    // BFS
    void bfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!q.empty())
        {
            long temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                {
                    q.push(vertex.first);
                    visited[vertex.first] = true;
                    result.push_back(vertex.first);
                }
            }
        }
    }

    // Dijkstra
    void dijkstra(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        priority_queue<pair<long, long>,
                       vector<pair<long, long>>,
                       greater<pair<long, long>>>
            pq;
        result = vector<long>(vertexCount, LONG_MAX);

        pq.push(make_pair(0, start));
        result[start] = 0;

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            if (visited[temp.second])
                continue;

            visited[temp.second] = true;

            for (auto vertex : adjList[temp.second])
            {
                long nextVertex = vertex.first;
                long weight = vertex.second;

                if (temp.first + weight < result[nextVertex])
                {
                    result[nextVertex] = temp.first + weight;
                    pq.push(make_pair(result[nextVertex], nextVertex));
                }
            }
        }
    }

    // DSU helpers
    long find_parent(vector<long> &parent, long v)
    {
        if (v == parent[v])
            return v;

        return parent[v] = find_parent(parent, parent[v]);
    }

    void union_set(vector<long> &parent, long vertex1, long vertex2)
    {
        int parent1 = find_parent(parent, vertex1);
        int parent2 = find_parent(parent, vertex2);

        if (parent1 != parent2)
            parent[parent2] = parent1;
    }

    // Kruskal
    void kruskal(vector<pair<long, pair<long, long>>> &result)
    {
        vector<long> parent;
        for (int i = 0; i < vertexCount; i++)
            parent.push_back(i);

        sort(edgeList.begin(), edgeList.end());

        for (auto edge : edgeList)
        {
            long vertex1 = edge.second.first;
            long vertex2 = edge.second.second;
            if (find_parent(parent, vertex1) != find_parent(parent, vertex2))
            {
                result.push_back(edge);
                union_set(parent, vertex1, vertex2);
                if (result.size() == vertexCount - 1)
                    return;
            }
        }
    }

    // Prim's
    long prims(long start, vector<pair<long, pair<long, long>>> &result)
    {
        vector<bool> inMST(vertexCount, false);
        priority_queue<pair<long, pair<long, long>>,
                       vector<pair<long, pair<long, long>>>,
                       greater<pair<long, pair<long, long>>>>
            pq;
        long mstWeight = 0;

        inMST[start] = true;
        for (auto edge : adjList[start])
        {
            pq.push({edge.second, {start, edge.first}});
        }

        while (!pq.empty() && result.size() < vertexCount - 1)
        {
            auto [w, uv] = pq.top();
            pq.pop();

            long u = uv.first;
            long v = uv.second;

            if (inMST[v]) continue;

            inMST[v] = true;
            result.push_back({w, {u, v}});
            mstWeight += w;

            for (auto edge : adjList[v])
            {
                if (!inMST[edge.first])
                {
                    pq.push({edge.second, {v, edge.first}});
                }
            }
        }

        return mstWeight;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        graph g;
        g.init(n);

        for (int i = 0; i < m; i++)
        {
            int v, u, w;
            cin >> v >> u >> w;
            --v; --u;
            g.add_edge(v, u, w);
        }

        int s;
        cin >> s;
        --s;

        vector<long> dist;
        g.dijkstra(dist, s);

        for (int i = 0; i < n; i++)
        {
            if (i == s) continue;
            cout << (dist[i] != LONG_MAX ? dist[i] : -1) << " ";
        }
        cout << "\n";
    }

    return 0;
}
